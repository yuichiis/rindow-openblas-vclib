#include <Windows.h>
#include <stdio.h>
#include <cblas.h>
#include "vclib.h"

static double storage[4096];
static float float_values[4096];
static double double_values[4096];
static blasint int_values[4096];
static enum CBLAS_TRANSPOSE enum_values[4096];
static void *pointer_values[64];
static const float *float_pointer_values[64];
static const double *double_pointer_values[64];
static void *complex_float_pointer_values[64];
static void *complex_double_pointer_values[64];

int main(void)
{
    size_t i;
    for (i = 0; i < sizeof(storage) / sizeof(storage[0]); ++i) storage[i] = 1.0;
    for (i = 0; i < sizeof(float_values) / sizeof(float_values[0]); ++i) float_values[i] = 1.0f;
    for (i = 0; i < sizeof(double_values) / sizeof(double_values[0]); ++i) double_values[i] = 1.0;
    for (i = 0; i < sizeof(int_values) / sizeof(int_values[0]); ++i) int_values[i] = 1;
    for (i = 0; i < sizeof(enum_values) / sizeof(enum_values[0]); ++i) enum_values[i] = CblasNoTrans;
    for (i = 0; i < sizeof(pointer_values) / sizeof(pointer_values[0]); ++i) pointer_values[i] = storage;
    for (i = 0; i < sizeof(float_pointer_values) / sizeof(float_pointer_values[0]); ++i) { float_pointer_values[i] = float_values; double_pointer_values[i] = double_values; complex_float_pointer_values[i] = float_values; complex_double_pointer_values[i] = double_values; }
    size_t called = 0, unavailable = 0;
    size_t not_invoked = 0;

    if (rindow_load_libopenblas_func("cblas_caxpby") == NULL) {
        fprintf(stderr, "SKIP cblas_caxpby: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_caxpby(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_caxpy") == NULL) {
        fprintf(stderr, "SKIP cblas_caxpy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_caxpy(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_caxpyc") == NULL) {
        fprintf(stderr, "SKIP cblas_caxpyc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_caxpyc(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ccopy") == NULL) {
        fprintf(stderr, "SKIP cblas_ccopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ccopy(1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cdotc") == NULL) {
        fprintf(stderr, "SKIP cblas_cdotc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cdotc(1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cdotc_sub") == NULL) {
        fprintf(stderr, "SKIP cblas_cdotc_sub: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cdotc_sub(1, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cdotu") == NULL) {
        fprintf(stderr, "SKIP cblas_cdotu: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cdotu(1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cdotu_sub") == NULL) {
        fprintf(stderr, "SKIP cblas_cdotu_sub: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cdotu_sub(1, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_cgbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgeadd") == NULL) {
        fprintf(stderr, "SKIP cblas_cgeadd: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgeadd(CblasRowMajor, 1, 1, (void *)storage, (void *)storage, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemm") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemm3m") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemm3m: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemm3m(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemm_batch") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemm_batch: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)float_values, complex_float_pointer_values, (blasint *)int_values, complex_float_pointer_values, (blasint *)int_values, (void *)float_values, complex_float_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemm_batch_strided") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemm_batch_strided: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, 1, (void *)float_values, 1, 1, (void *)float_values, (void *)float_values, 1, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemmt") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemmt: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgemv") == NULL) {
        fprintf(stderr, "SKIP cblas_cgemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgemv(CblasRowMajor, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgerc") == NULL) {
        fprintf(stderr, "SKIP cblas_cgerc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgerc(CblasRowMajor, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cgeru") == NULL) {
        fprintf(stderr, "SKIP cblas_cgeru: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cgeru(CblasRowMajor, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_chbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chbmv(CblasRowMajor, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chemm") == NULL) {
        fprintf(stderr, "SKIP cblas_chemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chemm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chemv") == NULL) {
        fprintf(stderr, "SKIP cblas_chemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chemv(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cher") == NULL) {
        fprintf(stderr, "SKIP cblas_cher: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cher(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cher2") == NULL) {
        fprintf(stderr, "SKIP cblas_cher2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cher2(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cher2k") == NULL) {
        fprintf(stderr, "SKIP cblas_cher2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, 1.0f, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cherk") == NULL) {
        fprintf(stderr, "SKIP cblas_cherk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cherk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (void *)float_values, 1, 1.0f, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_chpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chpmv(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chpr") == NULL) {
        fprintf(stderr, "SKIP cblas_chpr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chpr(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)float_values, 1, (void *)float_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_chpr2") == NULL) {
        fprintf(stderr, "SKIP cblas_chpr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_chpr2(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cimatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_cimatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (void *)storage, (void *)storage, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_comatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_comatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_comatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (void *)storage, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cscal") == NULL) {
        fprintf(stderr, "SKIP cblas_cscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cscal(1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_csscal") == NULL) {
        fprintf(stderr, "SKIP cblas_csscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_csscal(1, 1.0f, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_cswap") == NULL) {
        fprintf(stderr, "SKIP cblas_cswap: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_cswap(1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_csymm") == NULL) {
        fprintf(stderr, "SKIP cblas_csymm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_csymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_csyr2k") == NULL) {
        fprintf(stderr, "SKIP cblas_csyr2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_csyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_csyrk") == NULL) {
        fprintf(stderr, "SKIP cblas_csyrk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_csyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctbsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctbsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctpsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctpsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctrmm") == NULL) {
        fprintf(stderr, "SKIP cblas_ctrmm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctrmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctrmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctrsm") == NULL) {
        fprintf(stderr, "SKIP cblas_ctrsm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ctrsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ctrsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ctrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, 1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_damax") == NULL) {
        fprintf(stderr, "SKIP cblas_damax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_damax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_damin") == NULL) {
        fprintf(stderr, "SKIP cblas_damin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_damin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dasum") == NULL) {
        fprintf(stderr, "SKIP cblas_dasum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dasum(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_daxpby") == NULL) {
        fprintf(stderr, "SKIP cblas_daxpby: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_daxpby(1, 1.0, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_daxpy") == NULL) {
        fprintf(stderr, "SKIP cblas_daxpy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_daxpy(1, 1.0, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_dcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dcopy(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ddot") == NULL) {
        fprintf(stderr, "SKIP cblas_ddot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ddot(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dgbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgeadd") == NULL) {
        fprintf(stderr, "SKIP cblas_dgeadd: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgeadd(CblasRowMajor, 1, 1, 1.0, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgemm") == NULL) {
        fprintf(stderr, "SKIP cblas_dgemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgemm_batch") == NULL) {
        fprintf(stderr, "SKIP cblas_dgemm_batch: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)storage, (const double **)double_pointer_values, (blasint *)int_values, (const double **)double_pointer_values, (blasint *)int_values, (void *)storage, (const double **)double_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgemm_batch_strided") == NULL) {
        fprintf(stderr, "SKIP cblas_dgemm_batch_strided: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0, (void *)storage, 1, 1, (void *)storage, 1, 1, 1.0, (void *)storage, 1, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgemmt") == NULL) {
        fprintf(stderr, "SKIP cblas_dgemmt: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dgemv") == NULL) {
        fprintf(stderr, "SKIP cblas_dgemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dgemv(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dger") == NULL) {
        fprintf(stderr, "SKIP cblas_dger: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dger(CblasRowMajor, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dimatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_dimatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dnrm2") == NULL) {
        fprintf(stderr, "SKIP cblas_dnrm2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dnrm2(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_domatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_domatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_domatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_drot") == NULL) {
        fprintf(stderr, "SKIP cblas_drot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_drot(1, (void *)storage, 1, (void *)storage, 1, 1.0, 1.0);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_drotg") == NULL) {
        fprintf(stderr, "SKIP cblas_drotg: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_drotg((void *)storage, (void *)storage, (void *)storage, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_drotm") == NULL) {
        fprintf(stderr, "SKIP cblas_drotm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_drotm(1, (void *)storage, 1, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_drotmg") == NULL) {
        fprintf(stderr, "SKIP cblas_drotmg: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_drotmg((void *)storage, (void *)storage, (void *)storage, 1.0, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dsbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsbmv(CblasRowMajor, CblasUpper, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dscal") == NULL) {
        fprintf(stderr, "SKIP cblas_dscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dscal(1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsdot") == NULL) {
        fprintf(stderr, "SKIP cblas_dsdot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsdot(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dspmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dspmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dspmv(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dspr") == NULL) {
        fprintf(stderr, "SKIP cblas_dspr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dspr(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dspr2") == NULL) {
        fprintf(stderr, "SKIP cblas_dspr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dspr2(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, 1, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsum") == NULL) {
        fprintf(stderr, "SKIP cblas_dsum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsum(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dswap") == NULL) {
        fprintf(stderr, "SKIP cblas_dswap: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dswap(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsymm") == NULL) {
        fprintf(stderr, "SKIP cblas_dsymm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsymv") == NULL) {
        fprintf(stderr, "SKIP cblas_dsymv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsymv(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsyr") == NULL) {
        fprintf(stderr, "SKIP cblas_dsyr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsyr(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsyr2") == NULL) {
        fprintf(stderr, "SKIP cblas_dsyr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsyr2(CblasRowMajor, CblasUpper, 1, 1.0, (void *)storage, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsyr2k") == NULL) {
        fprintf(stderr, "SKIP cblas_dsyr2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dsyrk") == NULL) {
        fprintf(stderr, "SKIP cblas_dsyrk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (void *)storage, 1, 1.0, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtbsv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtbsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtpsv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtpsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtrmm") == NULL) {
        fprintf(stderr, "SKIP cblas_dtrmm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtrmv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtrmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtrsm") == NULL) {
        fprintf(stderr, "SKIP cblas_dtrsm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dtrsv") == NULL) {
        fprintf(stderr, "SKIP cblas_dtrsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dzamax") == NULL) {
        fprintf(stderr, "SKIP cblas_dzamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dzamax(1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dzamin") == NULL) {
        fprintf(stderr, "SKIP cblas_dzamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dzamin(1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dzasum") == NULL) {
        fprintf(stderr, "SKIP cblas_dzasum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dzasum(1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dznrm2") == NULL) {
        fprintf(stderr, "SKIP cblas_dznrm2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dznrm2(1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_dzsum") == NULL) {
        fprintf(stderr, "SKIP cblas_dzsum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_dzsum(1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_icamax") == NULL) {
        fprintf(stderr, "SKIP cblas_icamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_icamax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_icamin") == NULL) {
        fprintf(stderr, "SKIP cblas_icamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_icamin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_icmax") == NULL) {
        fprintf(stderr, "SKIP cblas_icmax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_icmax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_icmin") == NULL) {
        fprintf(stderr, "SKIP cblas_icmin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_icmin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_idamax") == NULL) {
        fprintf(stderr, "SKIP cblas_idamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_idamax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_idamin") == NULL) {
        fprintf(stderr, "SKIP cblas_idamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_idamin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_idmax") == NULL) {
        fprintf(stderr, "SKIP cblas_idmax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_idmax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_idmin") == NULL) {
        fprintf(stderr, "SKIP cblas_idmin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_idmin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_isamax") == NULL) {
        fprintf(stderr, "SKIP cblas_isamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_isamax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_isamin") == NULL) {
        fprintf(stderr, "SKIP cblas_isamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_isamin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ismax") == NULL) {
        fprintf(stderr, "SKIP cblas_ismax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ismax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ismin") == NULL) {
        fprintf(stderr, "SKIP cblas_ismin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ismin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_izamax") == NULL) {
        fprintf(stderr, "SKIP cblas_izamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_izamax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_izamin") == NULL) {
        fprintf(stderr, "SKIP cblas_izamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_izamin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_izmax") == NULL) {
        fprintf(stderr, "SKIP cblas_izmax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_izmax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_izmin") == NULL) {
        fprintf(stderr, "SKIP cblas_izmin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_izmin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_samax") == NULL) {
        fprintf(stderr, "SKIP cblas_samax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_samax(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_samin") == NULL) {
        fprintf(stderr, "SKIP cblas_samin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_samin(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sasum") == NULL) {
        fprintf(stderr, "SKIP cblas_sasum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sasum(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_saxpby") == NULL) {
        fprintf(stderr, "SKIP cblas_saxpby: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_saxpby(1, 1.0f, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_saxpy") == NULL) {
        fprintf(stderr, "SKIP cblas_saxpy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_saxpy(1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scamax") == NULL) {
        fprintf(stderr, "SKIP cblas_scamax: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scamax(1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scamin") == NULL) {
        fprintf(stderr, "SKIP cblas_scamin: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scamin(1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scasum") == NULL) {
        fprintf(stderr, "SKIP cblas_scasum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scasum(1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scnrm2") == NULL) {
        fprintf(stderr, "SKIP cblas_scnrm2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scnrm2(1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scopy") == NULL) {
        fprintf(stderr, "SKIP cblas_scopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scopy(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_scsum") == NULL) {
        fprintf(stderr, "SKIP cblas_scsum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_scsum(1, (void *)float_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sdot") == NULL) {
        fprintf(stderr, "SKIP cblas_sdot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sdot(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sdsdot") == NULL) {
        fprintf(stderr, "SKIP cblas_sdsdot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sdsdot(1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_sgbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgeadd") == NULL) {
        fprintf(stderr, "SKIP cblas_sgeadd: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgeadd(CblasRowMajor, 1, 1, 1.0f, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgemm") == NULL) {
        fprintf(stderr, "SKIP cblas_sgemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgemm_batch") == NULL) {
        fprintf(stderr, "SKIP cblas_sgemm_batch: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)storage, (const float **)float_pointer_values, (blasint *)int_values, (const float **)float_pointer_values, (blasint *)int_values, (void *)storage, (const float **)float_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgemm_batch_strided") == NULL) {
        fprintf(stderr, "SKIP cblas_sgemm_batch_strided: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0f, (void *)storage, 1, 1, (void *)storage, 1, 1, 1.0f, (void *)storage, 1, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgemmt") == NULL) {
        fprintf(stderr, "SKIP cblas_sgemmt: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sgemv") == NULL) {
        fprintf(stderr, "SKIP cblas_sgemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sgemv(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sger") == NULL) {
        fprintf(stderr, "SKIP cblas_sger: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sger(CblasRowMajor, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_simatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_simatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_simatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_snrm2") == NULL) {
        fprintf(stderr, "SKIP cblas_snrm2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_snrm2(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_somatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_somatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_somatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_srot") == NULL) {
        fprintf(stderr, "SKIP cblas_srot: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_srot(1, (void *)storage, 1, (void *)storage, 1, 1.0f, 1.0f);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_srotg") == NULL) {
        fprintf(stderr, "SKIP cblas_srotg: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_srotg((void *)storage, (void *)storage, (void *)storage, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_srotm") == NULL) {
        fprintf(stderr, "SKIP cblas_srotm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_srotm(1, (void *)storage, 1, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_srotmg") == NULL) {
        fprintf(stderr, "SKIP cblas_srotmg: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_srotmg((void *)storage, (void *)storage, (void *)storage, 1.0f, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ssbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssbmv(CblasRowMajor, CblasUpper, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sscal") == NULL) {
        fprintf(stderr, "SKIP cblas_sscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sscal(1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sspmv") == NULL) {
        fprintf(stderr, "SKIP cblas_sspmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sspmv(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sspr") == NULL) {
        fprintf(stderr, "SKIP cblas_sspr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sspr(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sspr2") == NULL) {
        fprintf(stderr, "SKIP cblas_sspr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sspr2(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, (void *)storage);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssum") == NULL) {
        fprintf(stderr, "SKIP cblas_ssum: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssum(1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_sswap") == NULL) {
        fprintf(stderr, "SKIP cblas_sswap: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_sswap(1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssymm") == NULL) {
        fprintf(stderr, "SKIP cblas_ssymm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssymv") == NULL) {
        fprintf(stderr, "SKIP cblas_ssymv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssymv(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssyr") == NULL) {
        fprintf(stderr, "SKIP cblas_ssyr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssyr(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssyr2") == NULL) {
        fprintf(stderr, "SKIP cblas_ssyr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssyr2(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssyr2k") == NULL) {
        fprintf(stderr, "SKIP cblas_ssyr2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ssyrk") == NULL) {
        fprintf(stderr, "SKIP cblas_ssyrk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ssyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (void *)storage, 1, 1.0f, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_stbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_stbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_stbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_stbsv") == NULL) {
        fprintf(stderr, "SKIP cblas_stbsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_stbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_stpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_stpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_stpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_stpsv") == NULL) {
        fprintf(stderr, "SKIP cblas_stpsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_stpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_strmm") == NULL) {
        fprintf(stderr, "SKIP cblas_strmm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_strmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_strmv") == NULL) {
        fprintf(stderr, "SKIP cblas_strmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_strmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_strsm") == NULL) {
        fprintf(stderr, "SKIP cblas_strsm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_strsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0f, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_strsv") == NULL) {
        fprintf(stderr, "SKIP cblas_strsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_strsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zaxpby") == NULL) {
        fprintf(stderr, "SKIP cblas_zaxpby: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zaxpby(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zaxpy") == NULL) {
        fprintf(stderr, "SKIP cblas_zaxpy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zaxpy(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zaxpyc") == NULL) {
        fprintf(stderr, "SKIP cblas_zaxpyc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zaxpyc(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_zcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zcopy(1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zdotc") == NULL) {
        fprintf(stderr, "SKIP cblas_zdotc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zdotc(1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zdotc_sub") == NULL) {
        fprintf(stderr, "SKIP cblas_zdotc_sub: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zdotc_sub(1, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zdotu") == NULL) {
        fprintf(stderr, "SKIP cblas_zdotu: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zdotu(1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zdotu_sub") == NULL) {
        fprintf(stderr, "SKIP cblas_zdotu_sub: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zdotu_sub(1, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zdscal") == NULL) {
        fprintf(stderr, "SKIP cblas_zdscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zdscal(1, 1.0, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_zgbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgeadd") == NULL) {
        fprintf(stderr, "SKIP cblas_zgeadd: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgeadd(CblasRowMajor, 1, 1, (void *)storage, (void *)storage, 1, (void *)storage, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemm") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemm3m") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemm3m: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemm3m(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemm_batch") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemm_batch: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)double_values, complex_double_pointer_values, (blasint *)int_values, complex_double_pointer_values, (blasint *)int_values, (void *)double_values, complex_double_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemm_batch_strided") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemm_batch_strided: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, 1, (void *)double_values, 1, 1, (void *)double_values, (void *)double_values, 1, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemmt") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemmt: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgemv") == NULL) {
        fprintf(stderr, "SKIP cblas_zgemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgemv(CblasRowMajor, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgerc") == NULL) {
        fprintf(stderr, "SKIP cblas_zgerc: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgerc(CblasRowMajor, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zgeru") == NULL) {
        fprintf(stderr, "SKIP cblas_zgeru: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zgeru(CblasRowMajor, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_zhbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhbmv(CblasRowMajor, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhemm") == NULL) {
        fprintf(stderr, "SKIP cblas_zhemm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhemm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhemv") == NULL) {
        fprintf(stderr, "SKIP cblas_zhemv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhemv(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zher") == NULL) {
        fprintf(stderr, "SKIP cblas_zher: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zher(CblasRowMajor, CblasUpper, 1, 1.0, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zher2") == NULL) {
        fprintf(stderr, "SKIP cblas_zher2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zher2(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zher2k") == NULL) {
        fprintf(stderr, "SKIP cblas_zher2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, 1.0, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zherk") == NULL) {
        fprintf(stderr, "SKIP cblas_zherk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zherk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (void *)double_values, 1, 1.0, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_zhpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhpmv(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhpr") == NULL) {
        fprintf(stderr, "SKIP cblas_zhpr: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhpr(CblasRowMajor, CblasUpper, 1, 1.0, (void *)double_values, 1, (void *)double_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zhpr2") == NULL) {
        fprintf(stderr, "SKIP cblas_zhpr2: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zhpr2(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zimatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_zimatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (void *)storage, (void *)storage, 1, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zomatcopy") == NULL) {
        fprintf(stderr, "SKIP cblas_zomatcopy: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zomatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (void *)storage, (void *)storage, 1, (void *)storage, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zscal") == NULL) {
        fprintf(stderr, "SKIP cblas_zscal: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zscal(1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zswap") == NULL) {
        fprintf(stderr, "SKIP cblas_zswap: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zswap(1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zsymm") == NULL) {
        fprintf(stderr, "SKIP cblas_zsymm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zsymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zsyr2k") == NULL) {
        fprintf(stderr, "SKIP cblas_zsyr2k: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zsyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_zsyrk") == NULL) {
        fprintf(stderr, "SKIP cblas_zsyrk: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_zsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztbmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztbmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztbsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztbsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztpmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztpmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztpsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztpsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztrmm") == NULL) {
        fprintf(stderr, "SKIP cblas_ztrmm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztrmv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztrmv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztrsm") == NULL) {
        fprintf(stderr, "SKIP cblas_ztrsm: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("cblas_ztrsv") == NULL) {
        fprintf(stderr, "SKIP cblas_ztrsv: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        cblas_ztrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, 1, (void *)double_values, 1);
        ++called;
    }
    if (rindow_load_libopenblas_func("goto_set_num_threads") == NULL) {
        fprintf(stderr, "SKIP goto_set_num_threads: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        goto_set_num_threads(0);
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_get_config") == NULL) {
        fprintf(stderr, "SKIP openblas_get_config: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_get_config();
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_get_corename") == NULL) {
        fprintf(stderr, "SKIP openblas_get_corename: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_get_corename();
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_get_num_procs") == NULL) {
        fprintf(stderr, "SKIP openblas_get_num_procs: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_get_num_procs();
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_get_num_threads") == NULL) {
        fprintf(stderr, "SKIP openblas_get_num_threads: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_get_num_threads();
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_get_parallel") == NULL) {
        fprintf(stderr, "SKIP openblas_get_parallel: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_get_parallel();
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_set_num_threads") == NULL) {
        fprintf(stderr, "SKIP openblas_set_num_threads: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_set_num_threads(0);
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_set_num_threads_local") == NULL) {
        fprintf(stderr, "SKIP openblas_set_num_threads_local: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_set_num_threads_local(0);
        ++called;
    }
    if (rindow_load_libopenblas_func("openblas_set_threads_callback_function") == NULL) {
        fprintf(stderr, "SKIP openblas_set_threads_callback_function: export unavailable in this OpenBLAS DLL\n");
        ++unavailable;
    } else {
        openblas_set_threads_callback_function(0);
        ++called;
    }
    printf("Called %llu wrappers; %llu exports unavailable; %llu grouped GEMM calls not invoked.\n", (unsigned long long)called, (unsigned long long)unavailable, (unsigned long long)not_invoked);
    return 0;
}
