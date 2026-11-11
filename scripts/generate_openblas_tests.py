"""Generate a smoke test that calls every non-16-bit wrapper in src."""

from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
OUT = ROOT / "tests" / "openblas_all_routines_test.cpp"
CBLAS_HEADER = Path("C:/OpenBLAS/OpenBLAS-0.3.33-x64/include/cblas.h")

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
        declaration = re.sub(r"\s*\*\s*", " * ", declaration)
        tokens = declaration.split()
        arg_name = tokens[-1].lstrip("*")
        pointer_count = declaration.count("*")
        arg_type = " ".join(tokens[:-1])
        args.append((arg_name, arg_type, pointer_count))
    return name, args


def read_sdk_signature(name):
    header = CBLAS_HEADER.read_text(encoding="utf-8", errors="replace")
    match = re.search(r"\b" + re.escape(name) + r"\s*\(", header)
    if not match:
        return None
    start = match.end()
    depth = 1
    end = start
    while end < len(header) and depth:
        if header[end] == "(":
            depth += 1
        elif header[end] == ")":
            depth -= 1
        end += 1
    raw = header[start:end - 1].strip()
    if raw == "void" or not raw:
        return []
    args = []
    for declaration in raw.split(","):
        declaration = re.sub(r"/\*.*?\*/", "", declaration).strip().rstrip(";")
        declaration = declaration.replace("OPENBLAS_CONST", "").strip()
        declaration = re.sub(r"\s*\*\s*", " * ", declaration)
        tokens = declaration.split()
        if not tokens:
            continue
        arg_name = tokens[-1].lstrip("*")
        pointer_count = declaration.count("*")
        arg_type = " ".join(tokens[:-1]).replace("const", "").strip()
        args.append((arg_name, arg_type, pointer_count))
    return args


def value_for(routine, name, arg_type, pointer_count):
    if pointer_count:
        normalized_type = arg_type.replace("const", "").replace("*", "").strip()
        if pointer_count > 1:
            if "float" in normalized_type:
                return "(float **)float_pointer_values" if name.startswith("C_") else "(const float **)float_pointer_values"
            if "double" in normalized_type:
                return "(double **)double_pointer_values" if name.startswith("C_") else "(const double **)double_pointer_values"
            if "void" in normalized_type:
                if routine.startswith("cblas_c"):
                    pointers = "complex_float_pointer_values"
                elif routine.startswith("cblas_z"):
                    pointers = "complex_double_pointer_values"
                else:
                    pointers = "pointer_values"
                return f"(void **) {pointers}" if name.startswith("C_") else f"(const void **) {pointers}"
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
    normalized_type = arg_type.replace("const", "").replace("*", "").strip()
    if "CBLAS_ORDER" in normalized_type:
        return "CblasRowMajor"
    if "CBLAS_TRANSPOSE" in normalized_type:
        return "CblasNoTrans"
    if "CBLAS_UPLO" in normalized_type:
        return "CblasUpper"
    if "CBLAS_DIAG" in normalized_type:
        return "CblasNonUnit"
    if "CBLAS_SIDE" in normalized_type:
        return "CblasLeft"
    if "char" in normalized_type:
        return '"Xgemm"'
    if normalized_type in ("float", "double"):
        return "1.0f" if normalized_type == "float" else "1.0"
    if "blasint" in normalized_type:
        if name == "group_count":
            return "0"
        if name in {"kl", "ku", "offset", "k1", "k2"}:
            return "0"
        return "1"
    if "bfloat16" in normalized_type:
        return "0"
    if "enum" in normalized_type:
        return "0"
    return "0"


wrappers = []
for source in sorted(SRC.glob("*.c")):
    if source.stem == "common" or source.stem in EXCLUDED:
        continue
    wrappers.append(read_signature(source))

lines = [
    "#include <Windows.h>",
    "#include <gtest/gtest.h>",
    "#include <cblas.h>",
    "#include \"vclib.h\"",
    "",
    "class OpenBLASRoutineTest : public ::testing::Test {",
    "protected:",
    "    double storage[4096] = {};",
    "    float float_values[4096] = {};",
    "    double double_values[4096] = {};",
    "    blasint int_values[4096] = {};",
    "    enum CBLAS_TRANSPOSE enum_values[4096] = {};",
    "    void *pointer_values[64] = {};",
    "    const float *float_pointer_values[64] = {};",
    "    const double *double_pointer_values[64] = {};",
    "    void *complex_float_pointer_values[64] = {};",
    "    void *complex_double_pointer_values[64] = {};",
    "",
    "    void SetUp() override {",
    "        for (size_t i = 0; i < 4096; ++i) {",
    "            storage[i] = 1.0;",
    "            float_values[i] = 1.0f;",
    "            double_values[i] = 1.0;",
    "            int_values[i] = 1;",
    "            enum_values[i] = CblasNoTrans;",
    "        }",
    "        for (size_t i = 0; i < 64; ++i) {",
    "            pointer_values[i] = storage;",
    "            float_pointer_values[i] = float_values;",
    "            double_pointer_values[i] = double_values;",
    "            complex_float_pointer_values[i] = float_values;",
    "            complex_double_pointer_values[i] = double_values;",
    "        }",
    "    }",
    "};",
    "",
]
for name, args in wrappers:
    sdk_args = read_sdk_signature(name)
    effective_args = args if sdk_args is None else [
        (source_arg[0], sdk_arg[1], sdk_arg[2])
        for source_arg, sdk_arg in zip(args, sdk_args)
    ]
    values = ", ".join(value_for(name, n, t, p) for n, t, p in effective_args)
    test_name = "".join(part.capitalize() for part in name.split("_"))
    lines += [
        f"TEST_F(OpenBLASRoutineTest, {test_name}) {{",
        f'    if (rindow_load_libopenblas_func("{name}") == nullptr) {{',
        f'        GTEST_SKIP() << "{name} is not exported by the OpenBLAS DLL";',
        "    }",
        f"    {name}({values});",
        "}",
        "",
    ]
lines += [
    "TEST_F(OpenBLASRoutineTest, SaxpyComputesExpectedResult) {",
    "    const float x[] = {1.0f, 2.0f, 3.0f};",
    "    float y[] = {10.0f, 20.0f, 30.0f};",
    '    if (rindow_load_libopenblas_func("cblas_saxpy") == nullptr) {',
    '        GTEST_SKIP() << "cblas_saxpy is not exported by the OpenBLAS DLL";',
    "    }",
    "    cblas_saxpy(3, 2.0f, x, 1, y, 1);",
    "    EXPECT_FLOAT_EQ(12.0f, y[0]);",
    "    EXPECT_FLOAT_EQ(24.0f, y[1]);",
    "    EXPECT_FLOAT_EQ(36.0f, y[2]);",
    "}",
    "",
]
OUT.write_text("\n".join(lines), encoding="utf-8")
print(f"Generated {OUT} with {len(wrappers)} wrapper calls")
