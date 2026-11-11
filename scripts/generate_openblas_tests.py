"""Generate a smoke test that calls every non-16-bit wrapper in src."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
OUT = ROOT / "tests" / "openblas_all_routines_test.c"

EXCLUDED = {
    # IEEE half precision and bfloat16 entry points (including mixed GEMM).
    "cblas_bgemm",
    "cblas_bgemv",
    "cblas_sbgemm_batch",
    "cblas_sbgemm_batch_strided",
    "cblas_shgemm",
}


def read_signature(path):
    source = path.read_text(encoding="utf-8")
    name = path.stem
    match = re.search(r"\b" + re.escape(name) + r"\s*\((.*?)\)\s*\{", source, re.S)
    if not match:
        raise ValueError(f"Could not parse wrapper signature: {path}")
    raw = match.group(1).strip()
    if raw == "void":
        return name, []
    args = []
    for declaration in raw.split(","):
        declaration = re.sub(r"/\*.*?\*/", "", declaration).strip()
        declaration = declaration.replace("OPENBLAS_CONST", "").strip()
        tokens = declaration.split()
        arg_name = tokens[-1].lstrip("*")
        pointer_count = declaration.count("*")
        arg_type = " ".join(tokens[:-1])
        args.append((arg_name, arg_type, pointer_count))
    return name, args


def value_for(routine, name, arg_type, pointer_count):
    if pointer_count:
        normalized_type = arg_type.replace("const", "").strip()
        if pointer_count > 1:
            if "float" in normalized_type:
                return "(const float **)float_pointer_values"
            if "double" in normalized_type:
                return "(const double **)double_pointer_values"
            if routine.startswith("cblas_c"):
                return "complex_float_pointer_values"
            if routine.startswith("cblas_z"):
                return "complex_double_pointer_values"
            if routine.startswith("cblas_d"):
                return "double_pointer_values"
            if routine.startswith("cblas_s"):
                return "float_pointer_values"
            return "(void **)pointer_values"
        if "openblas_threads_callback" in arg_type:
            return "NULL"
        if "blasint" in normalized_type:
            return "(blasint *)int_values"
        if "CBLAS_" in normalized_type:
            return "(enum CBLAS_TRANSPOSE *)enum_values"
        if normalized_type == "float":
            return "(float *)float_values"
        if normalized_type == "double":
            return "(double *)double_values"
        if "char" in normalized_type:
            return '"Xgemm"'
        if "void" in normalized_type:
            if routine.startswith("cblas_c"):
                return "(void *)float_values"
            if routine.startswith("cblas_z"):
                return "(void *)double_values"
            if routine.startswith("cblas_d"):
                return "(void *)double_values"
            if routine.startswith("cblas_s"):
                return "(void *)float_values"
        return "(void *)storage"
    if "CBLAS_ORDER" in arg_type:
        return "CblasRowMajor"
    if "CBLAS_TRANSPOSE" in arg_type:
        return "CblasNoTrans"
    if "CBLAS_UPLO" in arg_type:
        return "CblasUpper"
    if "CBLAS_DIAG" in arg_type:
        return "CblasNonUnit"
    if "CBLAS_SIDE" in arg_type:
        return "CblasLeft"
    if arg_type == "char" or "char" in arg_type:
        return '"Xgemm"'
    if arg_type in ("float", "double"):
        return "1.0f" if arg_type == "float" else "1.0"
    if "blasint" in arg_type:
        if name == "group_count":
            return "0"
        if name in {"kl", "ku", "offset", "k1", "k2"}:
            return "0"
        return "1"
    if "bfloat16" in arg_type:
        return "0"
    if "enum" in arg_type:
        return "0"
    return "0"


wrappers = []
for source in sorted(SRC.glob("*.c")):
    if source.stem == "common" or source.stem in EXCLUDED:
        continue
    wrappers.append(read_signature(source))

lines = [
    "#include <Windows.h>",
    "#include <stdio.h>",
    "#include <cblas.h>",
    "#include \"vclib.h\"",
    "",
    "static double storage[4096];",
    "static float float_values[4096];",
    "static double double_values[4096];",
    "static blasint int_values[4096];",
    "static enum CBLAS_TRANSPOSE enum_values[4096];",
    "static void *pointer_values[64];",
    "static const float *float_pointer_values[64];",
    "static const double *double_pointer_values[64];",
    "static void *complex_float_pointer_values[64];",
    "static void *complex_double_pointer_values[64];",
    "",
    "int main(void)",
    "{",
    "    size_t i;",
    "    for (i = 0; i < sizeof(storage) / sizeof(storage[0]); ++i) storage[i] = 1.0;",
    "    for (i = 0; i < sizeof(float_values) / sizeof(float_values[0]); ++i) float_values[i] = 1.0f;",
    "    for (i = 0; i < sizeof(double_values) / sizeof(double_values[0]); ++i) double_values[i] = 1.0;",
    "    for (i = 0; i < sizeof(int_values) / sizeof(int_values[0]); ++i) int_values[i] = 1;",
    "    for (i = 0; i < sizeof(enum_values) / sizeof(enum_values[0]); ++i) enum_values[i] = CblasNoTrans;",
    "    for (i = 0; i < sizeof(pointer_values) / sizeof(pointer_values[0]); ++i) pointer_values[i] = storage;",
    "    for (i = 0; i < sizeof(float_pointer_values) / sizeof(float_pointer_values[0]); ++i) { float_pointer_values[i] = float_values; double_pointer_values[i] = double_values; complex_float_pointer_values[i] = float_values; complex_double_pointer_values[i] = double_values; }",
    "    size_t called = 0, unavailable = 0;",
    "    size_t not_invoked = 0;",
    "",
]
for name, args in wrappers:
    values = ", ".join(value_for(name, n, t, p) for n, t, p in args)
    # Confirm the symbol exists in the loaded DLL before exercising its wrapper.
    lines += [
        f'    if (rindow_load_libopenblas_func("{name}") == NULL) {{',
        f'        fprintf(stderr, "SKIP {name}: export unavailable in this OpenBLAS DLL\\n");',
        "        ++unavailable;",
        "    } else {",
    ]
    lines += [
        f"        {name}({values});",
        "        ++called;",
    ]
    lines += [
        "    }",
    ]
lines += [
    '    printf("Called %llu wrappers; %llu exports unavailable; %llu grouped GEMM calls not invoked.\\n", (unsigned long long)called, (unsigned long long)unavailable, (unsigned long long)not_invoked);',
    "    return 0;",
    "}",
    "",
]
OUT.write_text("\n".join(lines), encoding="utf-8")
print(f"Generated {OUT} with {len(wrappers)} wrapper calls")
