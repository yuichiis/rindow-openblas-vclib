#include <Windows.h>
#include <gtest/gtest.h>
#include <cblas.h>
#include "vclib.h"

class OpenBLASRoutineTest : public ::testing::Test {
protected:
    double storage[4096] = {};
    float float_values[4096] = {};
    double double_values[4096] = {};
    blasint int_values[4096] = {};
    enum CBLAS_TRANSPOSE enum_values[4096] = {};
    void *pointer_values[64] = {};
    const float *float_pointer_values[64] = {};
    const double *double_pointer_values[64] = {};
    void *complex_float_pointer_values[64] = {};
    void *complex_double_pointer_values[64] = {};

    void SetUp() override {
        for (size_t i = 0; i < 4096; ++i) {
            storage[i] = 1.0;
            float_values[i] = 1.0f;
            double_values[i] = 1.0;
            int_values[i] = 1;
            enum_values[i] = CblasNoTrans;
        }
        for (size_t i = 0; i < 64; ++i) {
            pointer_values[i] = storage;
            float_pointer_values[i] = float_values;
            double_pointer_values[i] = double_values;
            complex_float_pointer_values[i] = float_values;
            complex_double_pointer_values[i] = double_values;
        }
    }
};

TEST_F(OpenBLASRoutineTest, CblasCaxpby) {
    if (rindow_load_libopenblas_func("cblas_caxpby") == nullptr) {
        GTEST_SKIP() << "cblas_caxpby is not exported by the OpenBLAS DLL";
    }
    cblas_caxpby(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCaxpy) {
    if (rindow_load_libopenblas_func("cblas_caxpy") == nullptr) {
        GTEST_SKIP() << "cblas_caxpy is not exported by the OpenBLAS DLL";
    }
    cblas_caxpy(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCaxpyc) {
    if (rindow_load_libopenblas_func("cblas_caxpyc") == nullptr) {
        GTEST_SKIP() << "cblas_caxpyc is not exported by the OpenBLAS DLL";
    }
    cblas_caxpyc(1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCcopy) {
    if (rindow_load_libopenblas_func("cblas_ccopy") == nullptr) {
        GTEST_SKIP() << "cblas_ccopy is not exported by the OpenBLAS DLL";
    }
    cblas_ccopy(1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCdotc) {
    if (rindow_load_libopenblas_func("cblas_cdotc") == nullptr) {
        GTEST_SKIP() << "cblas_cdotc is not exported by the OpenBLAS DLL";
    }
    cblas_cdotc(1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCdotcSub) {
    if (rindow_load_libopenblas_func("cblas_cdotc_sub") == nullptr) {
        GTEST_SKIP() << "cblas_cdotc_sub is not exported by the OpenBLAS DLL";
    }
    cblas_cdotc_sub(1, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasCdotu) {
    if (rindow_load_libopenblas_func("cblas_cdotu") == nullptr) {
        GTEST_SKIP() << "cblas_cdotu is not exported by the OpenBLAS DLL";
    }
    cblas_cdotu(1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCdotuSub) {
    if (rindow_load_libopenblas_func("cblas_cdotu_sub") == nullptr) {
        GTEST_SKIP() << "cblas_cdotu_sub is not exported by the OpenBLAS DLL";
    }
    cblas_cdotu_sub(1, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasCgbmv) {
    if (rindow_load_libopenblas_func("cblas_cgbmv") == nullptr) {
        GTEST_SKIP() << "cblas_cgbmv is not exported by the OpenBLAS DLL";
    }
    cblas_cgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgeadd) {
    if (rindow_load_libopenblas_func("cblas_cgeadd") == nullptr) {
        GTEST_SKIP() << "cblas_cgeadd is not exported by the OpenBLAS DLL";
    }
    cblas_cgeadd(CblasRowMajor, 1, 1, (float *)float_values, (float *)float_values, 1, (float *)float_values, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgemm) {
    if (rindow_load_libopenblas_func("cblas_cgemm") == nullptr) {
        GTEST_SKIP() << "cblas_cgemm is not exported by the OpenBLAS DLL";
    }
    cblas_cgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgemm3m) {
    if (rindow_load_libopenblas_func("cblas_cgemm3m") == nullptr) {
        GTEST_SKIP() << "cblas_cgemm3m is not exported by the OpenBLAS DLL";
    }
    cblas_cgemm3m(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgemmBatch) {
    if (rindow_load_libopenblas_func("cblas_cgemm_batch") == nullptr) {
        GTEST_SKIP() << "cblas_cgemm_batch is not exported by the OpenBLAS DLL";
    }
    cblas_cgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)float_values, (const void **) complex_float_pointer_values, (blasint *)int_values, (const void **) complex_float_pointer_values, (blasint *)int_values, (void *)float_values, (void **) complex_float_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
}

TEST_F(OpenBLASRoutineTest, CblasCgemmBatchStrided) {
    if (rindow_load_libopenblas_func("cblas_cgemm_batch_strided") == nullptr) {
        GTEST_SKIP() << "cblas_cgemm_batch_strided is not exported by the OpenBLAS DLL";
    }
    cblas_cgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)float_values, (void *)float_values, 1, 1, (void *)float_values, 1, 1, (void *)float_values, (void *)float_values, 1, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgemmt) {
    if (rindow_load_libopenblas_func("cblas_cgemmt") == nullptr) {
        GTEST_SKIP() << "cblas_cgemmt is not exported by the OpenBLAS DLL";
    }
    cblas_cgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgemv) {
    if (rindow_load_libopenblas_func("cblas_cgemv") == nullptr) {
        GTEST_SKIP() << "cblas_cgemv is not exported by the OpenBLAS DLL";
    }
    cblas_cgemv(CblasRowMajor, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgerc) {
    if (rindow_load_libopenblas_func("cblas_cgerc") == nullptr) {
        GTEST_SKIP() << "cblas_cgerc is not exported by the OpenBLAS DLL";
    }
    cblas_cgerc(CblasRowMajor, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCgeru) {
    if (rindow_load_libopenblas_func("cblas_cgeru") == nullptr) {
        GTEST_SKIP() << "cblas_cgeru is not exported by the OpenBLAS DLL";
    }
    cblas_cgeru(CblasRowMajor, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasChbmv) {
    if (rindow_load_libopenblas_func("cblas_chbmv") == nullptr) {
        GTEST_SKIP() << "cblas_chbmv is not exported by the OpenBLAS DLL";
    }
    cblas_chbmv(CblasRowMajor, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasChemm) {
    if (rindow_load_libopenblas_func("cblas_chemm") == nullptr) {
        GTEST_SKIP() << "cblas_chemm is not exported by the OpenBLAS DLL";
    }
    cblas_chemm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasChemv) {
    if (rindow_load_libopenblas_func("cblas_chemv") == nullptr) {
        GTEST_SKIP() << "cblas_chemv is not exported by the OpenBLAS DLL";
    }
    cblas_chemv(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCher) {
    if (rindow_load_libopenblas_func("cblas_cher") == nullptr) {
        GTEST_SKIP() << "cblas_cher is not exported by the OpenBLAS DLL";
    }
    cblas_cher(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCher2) {
    if (rindow_load_libopenblas_func("cblas_cher2") == nullptr) {
        GTEST_SKIP() << "cblas_cher2 is not exported by the OpenBLAS DLL";
    }
    cblas_cher2(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCher2k) {
    if (rindow_load_libopenblas_func("cblas_cher2k") == nullptr) {
        GTEST_SKIP() << "cblas_cher2k is not exported by the OpenBLAS DLL";
    }
    cblas_cher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, 1.0f, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCherk) {
    if (rindow_load_libopenblas_func("cblas_cherk") == nullptr) {
        GTEST_SKIP() << "cblas_cherk is not exported by the OpenBLAS DLL";
    }
    cblas_cherk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (void *)float_values, 1, 1.0f, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasChpmv) {
    if (rindow_load_libopenblas_func("cblas_chpmv") == nullptr) {
        GTEST_SKIP() << "cblas_chpmv is not exported by the OpenBLAS DLL";
    }
    cblas_chpmv(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasChpr) {
    if (rindow_load_libopenblas_func("cblas_chpr") == nullptr) {
        GTEST_SKIP() << "cblas_chpr is not exported by the OpenBLAS DLL";
    }
    cblas_chpr(CblasRowMajor, CblasUpper, 1, 1.0f, (void *)float_values, 1, (void *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasChpr2) {
    if (rindow_load_libopenblas_func("cblas_chpr2") == nullptr) {
        GTEST_SKIP() << "cblas_chpr2 is not exported by the OpenBLAS DLL";
    }
    cblas_chpr2(CblasRowMajor, CblasUpper, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasCimatcopy) {
    if (rindow_load_libopenblas_func("cblas_cimatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_cimatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_cimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (float *)float_values, (float *)float_values, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasComatcopy) {
    if (rindow_load_libopenblas_func("cblas_comatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_comatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_comatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (float *)float_values, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCrotg) {
    if (rindow_load_libopenblas_func("cblas_crotg") == nullptr) {
        GTEST_SKIP() << "cblas_crotg is not exported by the OpenBLAS DLL";
    }
    cblas_crotg((void *)float_values, (void *)float_values, (float *)float_values, (void *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasCscal) {
    if (rindow_load_libopenblas_func("cblas_cscal") == nullptr) {
        GTEST_SKIP() << "cblas_cscal is not exported by the OpenBLAS DLL";
    }
    cblas_cscal(1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCsrot) {
    if (rindow_load_libopenblas_func("cblas_csrot") == nullptr) {
        GTEST_SKIP() << "cblas_csrot is not exported by the OpenBLAS DLL";
    }
    cblas_csrot(1, (void *)float_values, 1, (void *)float_values, 1, 1.0f, 1.0f);
}

TEST_F(OpenBLASRoutineTest, CblasCsscal) {
    if (rindow_load_libopenblas_func("cblas_csscal") == nullptr) {
        GTEST_SKIP() << "cblas_csscal is not exported by the OpenBLAS DLL";
    }
    cblas_csscal(1, 1.0f, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCswap) {
    if (rindow_load_libopenblas_func("cblas_cswap") == nullptr) {
        GTEST_SKIP() << "cblas_cswap is not exported by the OpenBLAS DLL";
    }
    cblas_cswap(1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCsymm) {
    if (rindow_load_libopenblas_func("cblas_csymm") == nullptr) {
        GTEST_SKIP() << "cblas_csymm is not exported by the OpenBLAS DLL";
    }
    cblas_csymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCsyr2k) {
    if (rindow_load_libopenblas_func("cblas_csyr2k") == nullptr) {
        GTEST_SKIP() << "cblas_csyr2k is not exported by the OpenBLAS DLL";
    }
    cblas_csyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCsyrk) {
    if (rindow_load_libopenblas_func("cblas_csyrk") == nullptr) {
        GTEST_SKIP() << "cblas_csyrk is not exported by the OpenBLAS DLL";
    }
    cblas_csyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtbmv) {
    if (rindow_load_libopenblas_func("cblas_ctbmv") == nullptr) {
        GTEST_SKIP() << "cblas_ctbmv is not exported by the OpenBLAS DLL";
    }
    cblas_ctbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtbsv) {
    if (rindow_load_libopenblas_func("cblas_ctbsv") == nullptr) {
        GTEST_SKIP() << "cblas_ctbsv is not exported by the OpenBLAS DLL";
    }
    cblas_ctbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtpmv) {
    if (rindow_load_libopenblas_func("cblas_ctpmv") == nullptr) {
        GTEST_SKIP() << "cblas_ctpmv is not exported by the OpenBLAS DLL";
    }
    cblas_ctpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtpsv) {
    if (rindow_load_libopenblas_func("cblas_ctpsv") == nullptr) {
        GTEST_SKIP() << "cblas_ctpsv is not exported by the OpenBLAS DLL";
    }
    cblas_ctpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtrmm) {
    if (rindow_load_libopenblas_func("cblas_ctrmm") == nullptr) {
        GTEST_SKIP() << "cblas_ctrmm is not exported by the OpenBLAS DLL";
    }
    cblas_ctrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtrmv) {
    if (rindow_load_libopenblas_func("cblas_ctrmv") == nullptr) {
        GTEST_SKIP() << "cblas_ctrmv is not exported by the OpenBLAS DLL";
    }
    cblas_ctrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtrsm) {
    if (rindow_load_libopenblas_func("cblas_ctrsm") == nullptr) {
        GTEST_SKIP() << "cblas_ctrsm is not exported by the OpenBLAS DLL";
    }
    cblas_ctrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)float_values, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasCtrsv) {
    if (rindow_load_libopenblas_func("cblas_ctrsv") == nullptr) {
        GTEST_SKIP() << "cblas_ctrsv is not exported by the OpenBLAS DLL";
    }
    cblas_ctrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)float_values, 1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDamax) {
    if (rindow_load_libopenblas_func("cblas_damax") == nullptr) {
        GTEST_SKIP() << "cblas_damax is not exported by the OpenBLAS DLL";
    }
    cblas_damax(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDamin) {
    if (rindow_load_libopenblas_func("cblas_damin") == nullptr) {
        GTEST_SKIP() << "cblas_damin is not exported by the OpenBLAS DLL";
    }
    cblas_damin(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDasum) {
    if (rindow_load_libopenblas_func("cblas_dasum") == nullptr) {
        GTEST_SKIP() << "cblas_dasum is not exported by the OpenBLAS DLL";
    }
    cblas_dasum(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDaxpby) {
    if (rindow_load_libopenblas_func("cblas_daxpby") == nullptr) {
        GTEST_SKIP() << "cblas_daxpby is not exported by the OpenBLAS DLL";
    }
    cblas_daxpby(1, 1.0, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDaxpy) {
    if (rindow_load_libopenblas_func("cblas_daxpy") == nullptr) {
        GTEST_SKIP() << "cblas_daxpy is not exported by the OpenBLAS DLL";
    }
    cblas_daxpy(1, 1.0, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDcopy) {
    if (rindow_load_libopenblas_func("cblas_dcopy") == nullptr) {
        GTEST_SKIP() << "cblas_dcopy is not exported by the OpenBLAS DLL";
    }
    cblas_dcopy(1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDdot) {
    if (rindow_load_libopenblas_func("cblas_ddot") == nullptr) {
        GTEST_SKIP() << "cblas_ddot is not exported by the OpenBLAS DLL";
    }
    cblas_ddot(1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgbmv) {
    if (rindow_load_libopenblas_func("cblas_dgbmv") == nullptr) {
        GTEST_SKIP() << "cblas_dgbmv is not exported by the OpenBLAS DLL";
    }
    cblas_dgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgeadd) {
    if (rindow_load_libopenblas_func("cblas_dgeadd") == nullptr) {
        GTEST_SKIP() << "cblas_dgeadd is not exported by the OpenBLAS DLL";
    }
    cblas_dgeadd(CblasRowMajor, 1, 1, 1.0, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgemm) {
    if (rindow_load_libopenblas_func("cblas_dgemm") == nullptr) {
        GTEST_SKIP() << "cblas_dgemm is not exported by the OpenBLAS DLL";
    }
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgemmBatch) {
    if (rindow_load_libopenblas_func("cblas_dgemm_batch") == nullptr) {
        GTEST_SKIP() << "cblas_dgemm_batch is not exported by the OpenBLAS DLL";
    }
    cblas_dgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (double *)double_values, (const double **)double_pointer_values, (blasint *)int_values, (const double **)double_pointer_values, (blasint *)int_values, (double *)double_values, (double **)double_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
}

TEST_F(OpenBLASRoutineTest, CblasDgemmBatchStrided) {
    if (rindow_load_libopenblas_func("cblas_dgemm_batch_strided") == nullptr) {
        GTEST_SKIP() << "cblas_dgemm_batch_strided is not exported by the OpenBLAS DLL";
    }
    cblas_dgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0, (double *)double_values, 1, 1, (double *)double_values, 1, 1, 1.0, (double *)double_values, 1, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgemmt) {
    if (rindow_load_libopenblas_func("cblas_dgemmt") == nullptr) {
        GTEST_SKIP() << "cblas_dgemmt is not exported by the OpenBLAS DLL";
    }
    cblas_dgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDgemv) {
    if (rindow_load_libopenblas_func("cblas_dgemv") == nullptr) {
        GTEST_SKIP() << "cblas_dgemv is not exported by the OpenBLAS DLL";
    }
    cblas_dgemv(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDger) {
    if (rindow_load_libopenblas_func("cblas_dger") == nullptr) {
        GTEST_SKIP() << "cblas_dger is not exported by the OpenBLAS DLL";
    }
    cblas_dger(CblasRowMajor, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDimatcopy) {
    if (rindow_load_libopenblas_func("cblas_dimatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_dimatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_dimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDnrm2) {
    if (rindow_load_libopenblas_func("cblas_dnrm2") == nullptr) {
        GTEST_SKIP() << "cblas_dnrm2 is not exported by the OpenBLAS DLL";
    }
    cblas_dnrm2(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDomatcopy) {
    if (rindow_load_libopenblas_func("cblas_domatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_domatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_domatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDrot) {
    if (rindow_load_libopenblas_func("cblas_drot") == nullptr) {
        GTEST_SKIP() << "cblas_drot is not exported by the OpenBLAS DLL";
    }
    cblas_drot(1, (double *)double_values, 1, (double *)double_values, 1, 1.0, 1.0);
}

TEST_F(OpenBLASRoutineTest, CblasDrotg) {
    if (rindow_load_libopenblas_func("cblas_drotg") == nullptr) {
        GTEST_SKIP() << "cblas_drotg is not exported by the OpenBLAS DLL";
    }
    cblas_drotg((double *)double_values, (double *)double_values, (double *)double_values, (double *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasDrotm) {
    if (rindow_load_libopenblas_func("cblas_drotm") == nullptr) {
        GTEST_SKIP() << "cblas_drotm is not exported by the OpenBLAS DLL";
    }
    cblas_drotm(1, (double *)double_values, 1, (double *)double_values, 1, (double *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasDrotmg) {
    if (rindow_load_libopenblas_func("cblas_drotmg") == nullptr) {
        GTEST_SKIP() << "cblas_drotmg is not exported by the OpenBLAS DLL";
    }
    cblas_drotmg((double *)double_values, (double *)double_values, (double *)double_values, 1.0, (double *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasDsbmv) {
    if (rindow_load_libopenblas_func("cblas_dsbmv") == nullptr) {
        GTEST_SKIP() << "cblas_dsbmv is not exported by the OpenBLAS DLL";
    }
    cblas_dsbmv(CblasRowMajor, CblasUpper, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDscal) {
    if (rindow_load_libopenblas_func("cblas_dscal") == nullptr) {
        GTEST_SKIP() << "cblas_dscal is not exported by the OpenBLAS DLL";
    }
    cblas_dscal(1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsdot) {
    if (rindow_load_libopenblas_func("cblas_dsdot") == nullptr) {
        GTEST_SKIP() << "cblas_dsdot is not exported by the OpenBLAS DLL";
    }
    cblas_dsdot(1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDspmv) {
    if (rindow_load_libopenblas_func("cblas_dspmv") == nullptr) {
        GTEST_SKIP() << "cblas_dspmv is not exported by the OpenBLAS DLL";
    }
    cblas_dspmv(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDspr) {
    if (rindow_load_libopenblas_func("cblas_dspr") == nullptr) {
        GTEST_SKIP() << "cblas_dspr is not exported by the OpenBLAS DLL";
    }
    cblas_dspr(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, 1, (double *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasDspr2) {
    if (rindow_load_libopenblas_func("cblas_dspr2") == nullptr) {
        GTEST_SKIP() << "cblas_dspr2 is not exported by the OpenBLAS DLL";
    }
    cblas_dspr2(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, (double *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasDsum) {
    if (rindow_load_libopenblas_func("cblas_dsum") == nullptr) {
        GTEST_SKIP() << "cblas_dsum is not exported by the OpenBLAS DLL";
    }
    cblas_dsum(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDswap) {
    if (rindow_load_libopenblas_func("cblas_dswap") == nullptr) {
        GTEST_SKIP() << "cblas_dswap is not exported by the OpenBLAS DLL";
    }
    cblas_dswap(1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsymm) {
    if (rindow_load_libopenblas_func("cblas_dsymm") == nullptr) {
        GTEST_SKIP() << "cblas_dsymm is not exported by the OpenBLAS DLL";
    }
    cblas_dsymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsymv) {
    if (rindow_load_libopenblas_func("cblas_dsymv") == nullptr) {
        GTEST_SKIP() << "cblas_dsymv is not exported by the OpenBLAS DLL";
    }
    cblas_dsymv(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsyr) {
    if (rindow_load_libopenblas_func("cblas_dsyr") == nullptr) {
        GTEST_SKIP() << "cblas_dsyr is not exported by the OpenBLAS DLL";
    }
    cblas_dsyr(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsyr2) {
    if (rindow_load_libopenblas_func("cblas_dsyr2") == nullptr) {
        GTEST_SKIP() << "cblas_dsyr2 is not exported by the OpenBLAS DLL";
    }
    cblas_dsyr2(CblasRowMajor, CblasUpper, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsyr2k) {
    if (rindow_load_libopenblas_func("cblas_dsyr2k") == nullptr) {
        GTEST_SKIP() << "cblas_dsyr2k is not exported by the OpenBLAS DLL";
    }
    cblas_dsyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDsyrk) {
    if (rindow_load_libopenblas_func("cblas_dsyrk") == nullptr) {
        GTEST_SKIP() << "cblas_dsyrk is not exported by the OpenBLAS DLL";
    }
    cblas_dsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (double *)double_values, 1, 1.0, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtbmv) {
    if (rindow_load_libopenblas_func("cblas_dtbmv") == nullptr) {
        GTEST_SKIP() << "cblas_dtbmv is not exported by the OpenBLAS DLL";
    }
    cblas_dtbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtbsv) {
    if (rindow_load_libopenblas_func("cblas_dtbsv") == nullptr) {
        GTEST_SKIP() << "cblas_dtbsv is not exported by the OpenBLAS DLL";
    }
    cblas_dtbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtpmv) {
    if (rindow_load_libopenblas_func("cblas_dtpmv") == nullptr) {
        GTEST_SKIP() << "cblas_dtpmv is not exported by the OpenBLAS DLL";
    }
    cblas_dtpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (double *)double_values, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtpsv) {
    if (rindow_load_libopenblas_func("cblas_dtpsv") == nullptr) {
        GTEST_SKIP() << "cblas_dtpsv is not exported by the OpenBLAS DLL";
    }
    cblas_dtpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (double *)double_values, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtrmm) {
    if (rindow_load_libopenblas_func("cblas_dtrmm") == nullptr) {
        GTEST_SKIP() << "cblas_dtrmm is not exported by the OpenBLAS DLL";
    }
    cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtrmv) {
    if (rindow_load_libopenblas_func("cblas_dtrmv") == nullptr) {
        GTEST_SKIP() << "cblas_dtrmv is not exported by the OpenBLAS DLL";
    }
    cblas_dtrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtrsm) {
    if (rindow_load_libopenblas_func("cblas_dtrsm") == nullptr) {
        GTEST_SKIP() << "cblas_dtrsm is not exported by the OpenBLAS DLL";
    }
    cblas_dtrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDtrsv) {
    if (rindow_load_libopenblas_func("cblas_dtrsv") == nullptr) {
        GTEST_SKIP() << "cblas_dtrsv is not exported by the OpenBLAS DLL";
    }
    cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDzamax) {
    if (rindow_load_libopenblas_func("cblas_dzamax") == nullptr) {
        GTEST_SKIP() << "cblas_dzamax is not exported by the OpenBLAS DLL";
    }
    cblas_dzamax(1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDzamin) {
    if (rindow_load_libopenblas_func("cblas_dzamin") == nullptr) {
        GTEST_SKIP() << "cblas_dzamin is not exported by the OpenBLAS DLL";
    }
    cblas_dzamin(1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDzasum) {
    if (rindow_load_libopenblas_func("cblas_dzasum") == nullptr) {
        GTEST_SKIP() << "cblas_dzasum is not exported by the OpenBLAS DLL";
    }
    cblas_dzasum(1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDznrm2) {
    if (rindow_load_libopenblas_func("cblas_dznrm2") == nullptr) {
        GTEST_SKIP() << "cblas_dznrm2 is not exported by the OpenBLAS DLL";
    }
    cblas_dznrm2(1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasDzsum) {
    if (rindow_load_libopenblas_func("cblas_dzsum") == nullptr) {
        GTEST_SKIP() << "cblas_dzsum is not exported by the OpenBLAS DLL";
    }
    cblas_dzsum(1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIcamax) {
    if (rindow_load_libopenblas_func("cblas_icamax") == nullptr) {
        GTEST_SKIP() << "cblas_icamax is not exported by the OpenBLAS DLL";
    }
    cblas_icamax(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIcamin) {
    if (rindow_load_libopenblas_func("cblas_icamin") == nullptr) {
        GTEST_SKIP() << "cblas_icamin is not exported by the OpenBLAS DLL";
    }
    cblas_icamin(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIcmax) {
    if (rindow_load_libopenblas_func("cblas_icmax") == nullptr) {
        GTEST_SKIP() << "cblas_icmax is not exported by the OpenBLAS DLL";
    }
    cblas_icmax(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIcmin) {
    if (rindow_load_libopenblas_func("cblas_icmin") == nullptr) {
        GTEST_SKIP() << "cblas_icmin is not exported by the OpenBLAS DLL";
    }
    cblas_icmin(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIdamax) {
    if (rindow_load_libopenblas_func("cblas_idamax") == nullptr) {
        GTEST_SKIP() << "cblas_idamax is not exported by the OpenBLAS DLL";
    }
    cblas_idamax(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIdamin) {
    if (rindow_load_libopenblas_func("cblas_idamin") == nullptr) {
        GTEST_SKIP() << "cblas_idamin is not exported by the OpenBLAS DLL";
    }
    cblas_idamin(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIdmax) {
    if (rindow_load_libopenblas_func("cblas_idmax") == nullptr) {
        GTEST_SKIP() << "cblas_idmax is not exported by the OpenBLAS DLL";
    }
    cblas_idmax(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIdmin) {
    if (rindow_load_libopenblas_func("cblas_idmin") == nullptr) {
        GTEST_SKIP() << "cblas_idmin is not exported by the OpenBLAS DLL";
    }
    cblas_idmin(1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIsamax) {
    if (rindow_load_libopenblas_func("cblas_isamax") == nullptr) {
        GTEST_SKIP() << "cblas_isamax is not exported by the OpenBLAS DLL";
    }
    cblas_isamax(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIsamin) {
    if (rindow_load_libopenblas_func("cblas_isamin") == nullptr) {
        GTEST_SKIP() << "cblas_isamin is not exported by the OpenBLAS DLL";
    }
    cblas_isamin(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIsmax) {
    if (rindow_load_libopenblas_func("cblas_ismax") == nullptr) {
        GTEST_SKIP() << "cblas_ismax is not exported by the OpenBLAS DLL";
    }
    cblas_ismax(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIsmin) {
    if (rindow_load_libopenblas_func("cblas_ismin") == nullptr) {
        GTEST_SKIP() << "cblas_ismin is not exported by the OpenBLAS DLL";
    }
    cblas_ismin(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIzamax) {
    if (rindow_load_libopenblas_func("cblas_izamax") == nullptr) {
        GTEST_SKIP() << "cblas_izamax is not exported by the OpenBLAS DLL";
    }
    cblas_izamax(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIzamin) {
    if (rindow_load_libopenblas_func("cblas_izamin") == nullptr) {
        GTEST_SKIP() << "cblas_izamin is not exported by the OpenBLAS DLL";
    }
    cblas_izamin(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIzmax) {
    if (rindow_load_libopenblas_func("cblas_izmax") == nullptr) {
        GTEST_SKIP() << "cblas_izmax is not exported by the OpenBLAS DLL";
    }
    cblas_izmax(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasIzmin) {
    if (rindow_load_libopenblas_func("cblas_izmin") == nullptr) {
        GTEST_SKIP() << "cblas_izmin is not exported by the OpenBLAS DLL";
    }
    cblas_izmin(1, (void *)storage, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSamax) {
    if (rindow_load_libopenblas_func("cblas_samax") == nullptr) {
        GTEST_SKIP() << "cblas_samax is not exported by the OpenBLAS DLL";
    }
    cblas_samax(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSamin) {
    if (rindow_load_libopenblas_func("cblas_samin") == nullptr) {
        GTEST_SKIP() << "cblas_samin is not exported by the OpenBLAS DLL";
    }
    cblas_samin(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSasum) {
    if (rindow_load_libopenblas_func("cblas_sasum") == nullptr) {
        GTEST_SKIP() << "cblas_sasum is not exported by the OpenBLAS DLL";
    }
    cblas_sasum(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSaxpby) {
    if (rindow_load_libopenblas_func("cblas_saxpby") == nullptr) {
        GTEST_SKIP() << "cblas_saxpby is not exported by the OpenBLAS DLL";
    }
    cblas_saxpby(1, 1.0f, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSaxpy) {
    if (rindow_load_libopenblas_func("cblas_saxpy") == nullptr) {
        GTEST_SKIP() << "cblas_saxpy is not exported by the OpenBLAS DLL";
    }
    cblas_saxpy(1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScamax) {
    if (rindow_load_libopenblas_func("cblas_scamax") == nullptr) {
        GTEST_SKIP() << "cblas_scamax is not exported by the OpenBLAS DLL";
    }
    cblas_scamax(1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScamin) {
    if (rindow_load_libopenblas_func("cblas_scamin") == nullptr) {
        GTEST_SKIP() << "cblas_scamin is not exported by the OpenBLAS DLL";
    }
    cblas_scamin(1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScasum) {
    if (rindow_load_libopenblas_func("cblas_scasum") == nullptr) {
        GTEST_SKIP() << "cblas_scasum is not exported by the OpenBLAS DLL";
    }
    cblas_scasum(1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScnrm2) {
    if (rindow_load_libopenblas_func("cblas_scnrm2") == nullptr) {
        GTEST_SKIP() << "cblas_scnrm2 is not exported by the OpenBLAS DLL";
    }
    cblas_scnrm2(1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScopy) {
    if (rindow_load_libopenblas_func("cblas_scopy") == nullptr) {
        GTEST_SKIP() << "cblas_scopy is not exported by the OpenBLAS DLL";
    }
    cblas_scopy(1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasScsum) {
    if (rindow_load_libopenblas_func("cblas_scsum") == nullptr) {
        GTEST_SKIP() << "cblas_scsum is not exported by the OpenBLAS DLL";
    }
    cblas_scsum(1, (void *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSdot) {
    if (rindow_load_libopenblas_func("cblas_sdot") == nullptr) {
        GTEST_SKIP() << "cblas_sdot is not exported by the OpenBLAS DLL";
    }
    cblas_sdot(1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSdsdot) {
    if (rindow_load_libopenblas_func("cblas_sdsdot") == nullptr) {
        GTEST_SKIP() << "cblas_sdsdot is not exported by the OpenBLAS DLL";
    }
    cblas_sdsdot(1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgbmv) {
    if (rindow_load_libopenblas_func("cblas_sgbmv") == nullptr) {
        GTEST_SKIP() << "cblas_sgbmv is not exported by the OpenBLAS DLL";
    }
    cblas_sgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgeadd) {
    if (rindow_load_libopenblas_func("cblas_sgeadd") == nullptr) {
        GTEST_SKIP() << "cblas_sgeadd is not exported by the OpenBLAS DLL";
    }
    cblas_sgeadd(CblasRowMajor, 1, 1, 1.0f, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgemm) {
    if (rindow_load_libopenblas_func("cblas_sgemm") == nullptr) {
        GTEST_SKIP() << "cblas_sgemm is not exported by the OpenBLAS DLL";
    }
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgemmBatch) {
    if (rindow_load_libopenblas_func("cblas_sgemm_batch") == nullptr) {
        GTEST_SKIP() << "cblas_sgemm_batch is not exported by the OpenBLAS DLL";
    }
    cblas_sgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (float *)float_values, (const float **)float_pointer_values, (blasint *)int_values, (const float **)float_pointer_values, (blasint *)int_values, (float *)float_values, (float **)float_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
}

TEST_F(OpenBLASRoutineTest, CblasSgemmBatchStrided) {
    if (rindow_load_libopenblas_func("cblas_sgemm_batch_strided") == nullptr) {
        GTEST_SKIP() << "cblas_sgemm_batch_strided is not exported by the OpenBLAS DLL";
    }
    cblas_sgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, 1.0f, (float *)float_values, 1, 1, (float *)float_values, 1, 1, 1.0f, (float *)float_values, 1, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgemmt) {
    if (rindow_load_libopenblas_func("cblas_sgemmt") == nullptr) {
        GTEST_SKIP() << "cblas_sgemmt is not exported by the OpenBLAS DLL";
    }
    cblas_sgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSgemv) {
    if (rindow_load_libopenblas_func("cblas_sgemv") == nullptr) {
        GTEST_SKIP() << "cblas_sgemv is not exported by the OpenBLAS DLL";
    }
    cblas_sgemv(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSger) {
    if (rindow_load_libopenblas_func("cblas_sger") == nullptr) {
        GTEST_SKIP() << "cblas_sger is not exported by the OpenBLAS DLL";
    }
    cblas_sger(CblasRowMajor, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSimatcopy) {
    if (rindow_load_libopenblas_func("cblas_simatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_simatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_simatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSnrm2) {
    if (rindow_load_libopenblas_func("cblas_snrm2") == nullptr) {
        GTEST_SKIP() << "cblas_snrm2 is not exported by the OpenBLAS DLL";
    }
    cblas_snrm2(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSomatcopy) {
    if (rindow_load_libopenblas_func("cblas_somatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_somatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_somatcopy(CblasRowMajor, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSrot) {
    if (rindow_load_libopenblas_func("cblas_srot") == nullptr) {
        GTEST_SKIP() << "cblas_srot is not exported by the OpenBLAS DLL";
    }
    cblas_srot(1, (float *)float_values, 1, (float *)float_values, 1, 1.0f, 1.0f);
}

TEST_F(OpenBLASRoutineTest, CblasSrotg) {
    if (rindow_load_libopenblas_func("cblas_srotg") == nullptr) {
        GTEST_SKIP() << "cblas_srotg is not exported by the OpenBLAS DLL";
    }
    cblas_srotg((float *)float_values, (float *)float_values, (float *)float_values, (float *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasSrotm) {
    if (rindow_load_libopenblas_func("cblas_srotm") == nullptr) {
        GTEST_SKIP() << "cblas_srotm is not exported by the OpenBLAS DLL";
    }
    cblas_srotm(1, (float *)float_values, 1, (float *)float_values, 1, (float *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasSrotmg) {
    if (rindow_load_libopenblas_func("cblas_srotmg") == nullptr) {
        GTEST_SKIP() << "cblas_srotmg is not exported by the OpenBLAS DLL";
    }
    cblas_srotmg((float *)float_values, (float *)float_values, (float *)float_values, 1.0f, (float *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasSsbmv) {
    if (rindow_load_libopenblas_func("cblas_ssbmv") == nullptr) {
        GTEST_SKIP() << "cblas_ssbmv is not exported by the OpenBLAS DLL";
    }
    cblas_ssbmv(CblasRowMajor, CblasUpper, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSscal) {
    if (rindow_load_libopenblas_func("cblas_sscal") == nullptr) {
        GTEST_SKIP() << "cblas_sscal is not exported by the OpenBLAS DLL";
    }
    cblas_sscal(1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSspmv) {
    if (rindow_load_libopenblas_func("cblas_sspmv") == nullptr) {
        GTEST_SKIP() << "cblas_sspmv is not exported by the OpenBLAS DLL";
    }
    cblas_sspmv(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSspr) {
    if (rindow_load_libopenblas_func("cblas_sspr") == nullptr) {
        GTEST_SKIP() << "cblas_sspr is not exported by the OpenBLAS DLL";
    }
    cblas_sspr(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, 1, (float *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasSspr2) {
    if (rindow_load_libopenblas_func("cblas_sspr2") == nullptr) {
        GTEST_SKIP() << "cblas_sspr2 is not exported by the OpenBLAS DLL";
    }
    cblas_sspr2(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, (float *)float_values);
}

TEST_F(OpenBLASRoutineTest, CblasSsum) {
    if (rindow_load_libopenblas_func("cblas_ssum") == nullptr) {
        GTEST_SKIP() << "cblas_ssum is not exported by the OpenBLAS DLL";
    }
    cblas_ssum(1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSswap) {
    if (rindow_load_libopenblas_func("cblas_sswap") == nullptr) {
        GTEST_SKIP() << "cblas_sswap is not exported by the OpenBLAS DLL";
    }
    cblas_sswap(1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsymm) {
    if (rindow_load_libopenblas_func("cblas_ssymm") == nullptr) {
        GTEST_SKIP() << "cblas_ssymm is not exported by the OpenBLAS DLL";
    }
    cblas_ssymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsymv) {
    if (rindow_load_libopenblas_func("cblas_ssymv") == nullptr) {
        GTEST_SKIP() << "cblas_ssymv is not exported by the OpenBLAS DLL";
    }
    cblas_ssymv(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsyr) {
    if (rindow_load_libopenblas_func("cblas_ssyr") == nullptr) {
        GTEST_SKIP() << "cblas_ssyr is not exported by the OpenBLAS DLL";
    }
    cblas_ssyr(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsyr2) {
    if (rindow_load_libopenblas_func("cblas_ssyr2") == nullptr) {
        GTEST_SKIP() << "cblas_ssyr2 is not exported by the OpenBLAS DLL";
    }
    cblas_ssyr2(CblasRowMajor, CblasUpper, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsyr2k) {
    if (rindow_load_libopenblas_func("cblas_ssyr2k") == nullptr) {
        GTEST_SKIP() << "cblas_ssyr2k is not exported by the OpenBLAS DLL";
    }
    cblas_ssyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasSsyrk) {
    if (rindow_load_libopenblas_func("cblas_ssyrk") == nullptr) {
        GTEST_SKIP() << "cblas_ssyrk is not exported by the OpenBLAS DLL";
    }
    cblas_ssyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0f, (float *)float_values, 1, 1.0f, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStbmv) {
    if (rindow_load_libopenblas_func("cblas_stbmv") == nullptr) {
        GTEST_SKIP() << "cblas_stbmv is not exported by the OpenBLAS DLL";
    }
    cblas_stbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStbsv) {
    if (rindow_load_libopenblas_func("cblas_stbsv") == nullptr) {
        GTEST_SKIP() << "cblas_stbsv is not exported by the OpenBLAS DLL";
    }
    cblas_stbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStpmv) {
    if (rindow_load_libopenblas_func("cblas_stpmv") == nullptr) {
        GTEST_SKIP() << "cblas_stpmv is not exported by the OpenBLAS DLL";
    }
    cblas_stpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (float *)float_values, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStpsv) {
    if (rindow_load_libopenblas_func("cblas_stpsv") == nullptr) {
        GTEST_SKIP() << "cblas_stpsv is not exported by the OpenBLAS DLL";
    }
    cblas_stpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (float *)float_values, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStrmm) {
    if (rindow_load_libopenblas_func("cblas_strmm") == nullptr) {
        GTEST_SKIP() << "cblas_strmm is not exported by the OpenBLAS DLL";
    }
    cblas_strmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStrmv) {
    if (rindow_load_libopenblas_func("cblas_strmv") == nullptr) {
        GTEST_SKIP() << "cblas_strmv is not exported by the OpenBLAS DLL";
    }
    cblas_strmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStrsm) {
    if (rindow_load_libopenblas_func("cblas_strsm") == nullptr) {
        GTEST_SKIP() << "cblas_strsm is not exported by the OpenBLAS DLL";
    }
    cblas_strsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, 1.0f, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasStrsv) {
    if (rindow_load_libopenblas_func("cblas_strsv") == nullptr) {
        GTEST_SKIP() << "cblas_strsv is not exported by the OpenBLAS DLL";
    }
    cblas_strsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (float *)float_values, 1, (float *)float_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZaxpby) {
    if (rindow_load_libopenblas_func("cblas_zaxpby") == nullptr) {
        GTEST_SKIP() << "cblas_zaxpby is not exported by the OpenBLAS DLL";
    }
    cblas_zaxpby(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZaxpy) {
    if (rindow_load_libopenblas_func("cblas_zaxpy") == nullptr) {
        GTEST_SKIP() << "cblas_zaxpy is not exported by the OpenBLAS DLL";
    }
    cblas_zaxpy(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZaxpyc) {
    if (rindow_load_libopenblas_func("cblas_zaxpyc") == nullptr) {
        GTEST_SKIP() << "cblas_zaxpyc is not exported by the OpenBLAS DLL";
    }
    cblas_zaxpyc(1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZcopy) {
    if (rindow_load_libopenblas_func("cblas_zcopy") == nullptr) {
        GTEST_SKIP() << "cblas_zcopy is not exported by the OpenBLAS DLL";
    }
    cblas_zcopy(1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZdotc) {
    if (rindow_load_libopenblas_func("cblas_zdotc") == nullptr) {
        GTEST_SKIP() << "cblas_zdotc is not exported by the OpenBLAS DLL";
    }
    cblas_zdotc(1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZdotcSub) {
    if (rindow_load_libopenblas_func("cblas_zdotc_sub") == nullptr) {
        GTEST_SKIP() << "cblas_zdotc_sub is not exported by the OpenBLAS DLL";
    }
    cblas_zdotc_sub(1, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasZdotu) {
    if (rindow_load_libopenblas_func("cblas_zdotu") == nullptr) {
        GTEST_SKIP() << "cblas_zdotu is not exported by the OpenBLAS DLL";
    }
    cblas_zdotu(1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZdotuSub) {
    if (rindow_load_libopenblas_func("cblas_zdotu_sub") == nullptr) {
        GTEST_SKIP() << "cblas_zdotu_sub is not exported by the OpenBLAS DLL";
    }
    cblas_zdotu_sub(1, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasZdrot) {
    if (rindow_load_libopenblas_func("cblas_zdrot") == nullptr) {
        GTEST_SKIP() << "cblas_zdrot is not exported by the OpenBLAS DLL";
    }
    cblas_zdrot(1, (void *)double_values, 1, (void *)double_values, 1, 1.0, 1.0);
}

TEST_F(OpenBLASRoutineTest, CblasZdscal) {
    if (rindow_load_libopenblas_func("cblas_zdscal") == nullptr) {
        GTEST_SKIP() << "cblas_zdscal is not exported by the OpenBLAS DLL";
    }
    cblas_zdscal(1, 1.0, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgbmv) {
    if (rindow_load_libopenblas_func("cblas_zgbmv") == nullptr) {
        GTEST_SKIP() << "cblas_zgbmv is not exported by the OpenBLAS DLL";
    }
    cblas_zgbmv(CblasRowMajor, CblasNoTrans, 1, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgeadd) {
    if (rindow_load_libopenblas_func("cblas_zgeadd") == nullptr) {
        GTEST_SKIP() << "cblas_zgeadd is not exported by the OpenBLAS DLL";
    }
    cblas_zgeadd(CblasRowMajor, 1, 1, (double *)double_values, (double *)double_values, 1, (double *)double_values, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgemm) {
    if (rindow_load_libopenblas_func("cblas_zgemm") == nullptr) {
        GTEST_SKIP() << "cblas_zgemm is not exported by the OpenBLAS DLL";
    }
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgemm3m) {
    if (rindow_load_libopenblas_func("cblas_zgemm3m") == nullptr) {
        GTEST_SKIP() << "cblas_zgemm3m is not exported by the OpenBLAS DLL";
    }
    cblas_zgemm3m(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgemmBatch) {
    if (rindow_load_libopenblas_func("cblas_zgemm_batch") == nullptr) {
        GTEST_SKIP() << "cblas_zgemm_batch is not exported by the OpenBLAS DLL";
    }
    cblas_zgemm_batch(CblasRowMajor, (enum CBLAS_TRANSPOSE *)enum_values, (enum CBLAS_TRANSPOSE *)enum_values, (blasint *)int_values, (blasint *)int_values, (blasint *)int_values, (void *)double_values, (const void **) complex_double_pointer_values, (blasint *)int_values, (const void **) complex_double_pointer_values, (blasint *)int_values, (void *)double_values, (void **) complex_double_pointer_values, (blasint *)int_values, 0, (blasint *)int_values);
}

TEST_F(OpenBLASRoutineTest, CblasZgemmBatchStrided) {
    if (rindow_load_libopenblas_func("cblas_zgemm_batch_strided") == nullptr) {
        GTEST_SKIP() << "cblas_zgemm_batch_strided is not exported by the OpenBLAS DLL";
    }
    cblas_zgemm_batch_strided(CblasRowMajor, CblasNoTrans, CblasNoTrans, 1, 1, 1, (void *)double_values, (void *)double_values, 1, 1, (void *)double_values, 1, 1, (void *)double_values, (void *)double_values, 1, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgemmt) {
    if (rindow_load_libopenblas_func("cblas_zgemmt") == nullptr) {
        GTEST_SKIP() << "cblas_zgemmt is not exported by the OpenBLAS DLL";
    }
    cblas_zgemmt(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgemv) {
    if (rindow_load_libopenblas_func("cblas_zgemv") == nullptr) {
        GTEST_SKIP() << "cblas_zgemv is not exported by the OpenBLAS DLL";
    }
    cblas_zgemv(CblasRowMajor, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgerc) {
    if (rindow_load_libopenblas_func("cblas_zgerc") == nullptr) {
        GTEST_SKIP() << "cblas_zgerc is not exported by the OpenBLAS DLL";
    }
    cblas_zgerc(CblasRowMajor, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZgeru) {
    if (rindow_load_libopenblas_func("cblas_zgeru") == nullptr) {
        GTEST_SKIP() << "cblas_zgeru is not exported by the OpenBLAS DLL";
    }
    cblas_zgeru(CblasRowMajor, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZhbmv) {
    if (rindow_load_libopenblas_func("cblas_zhbmv") == nullptr) {
        GTEST_SKIP() << "cblas_zhbmv is not exported by the OpenBLAS DLL";
    }
    cblas_zhbmv(CblasRowMajor, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZhemm) {
    if (rindow_load_libopenblas_func("cblas_zhemm") == nullptr) {
        GTEST_SKIP() << "cblas_zhemm is not exported by the OpenBLAS DLL";
    }
    cblas_zhemm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZhemv) {
    if (rindow_load_libopenblas_func("cblas_zhemv") == nullptr) {
        GTEST_SKIP() << "cblas_zhemv is not exported by the OpenBLAS DLL";
    }
    cblas_zhemv(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZher) {
    if (rindow_load_libopenblas_func("cblas_zher") == nullptr) {
        GTEST_SKIP() << "cblas_zher is not exported by the OpenBLAS DLL";
    }
    cblas_zher(CblasRowMajor, CblasUpper, 1, 1.0, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZher2) {
    if (rindow_load_libopenblas_func("cblas_zher2") == nullptr) {
        GTEST_SKIP() << "cblas_zher2 is not exported by the OpenBLAS DLL";
    }
    cblas_zher2(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZher2k) {
    if (rindow_load_libopenblas_func("cblas_zher2k") == nullptr) {
        GTEST_SKIP() << "cblas_zher2k is not exported by the OpenBLAS DLL";
    }
    cblas_zher2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, 1.0, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZherk) {
    if (rindow_load_libopenblas_func("cblas_zherk") == nullptr) {
        GTEST_SKIP() << "cblas_zherk is not exported by the OpenBLAS DLL";
    }
    cblas_zherk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, 1.0, (void *)double_values, 1, 1.0, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZhpmv) {
    if (rindow_load_libopenblas_func("cblas_zhpmv") == nullptr) {
        GTEST_SKIP() << "cblas_zhpmv is not exported by the OpenBLAS DLL";
    }
    cblas_zhpmv(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZhpr) {
    if (rindow_load_libopenblas_func("cblas_zhpr") == nullptr) {
        GTEST_SKIP() << "cblas_zhpr is not exported by the OpenBLAS DLL";
    }
    cblas_zhpr(CblasRowMajor, CblasUpper, 1, 1.0, (void *)double_values, 1, (void *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasZhpr2) {
    if (rindow_load_libopenblas_func("cblas_zhpr2") == nullptr) {
        GTEST_SKIP() << "cblas_zhpr2 is not exported by the OpenBLAS DLL";
    }
    cblas_zhpr2(CblasRowMajor, CblasUpper, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasZimatcopy) {
    if (rindow_load_libopenblas_func("cblas_zimatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_zimatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_zimatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (double *)double_values, (double *)double_values, 1, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZomatcopy) {
    if (rindow_load_libopenblas_func("cblas_zomatcopy") == nullptr) {
        GTEST_SKIP() << "cblas_zomatcopy is not exported by the OpenBLAS DLL";
    }
    cblas_zomatcopy(CblasRowMajor, CblasNoTrans, 1, 1, (double *)double_values, (double *)double_values, 1, (double *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZrotg) {
    if (rindow_load_libopenblas_func("cblas_zrotg") == nullptr) {
        GTEST_SKIP() << "cblas_zrotg is not exported by the OpenBLAS DLL";
    }
    cblas_zrotg((void *)double_values, (void *)double_values, (double *)double_values, (void *)double_values);
}

TEST_F(OpenBLASRoutineTest, CblasZscal) {
    if (rindow_load_libopenblas_func("cblas_zscal") == nullptr) {
        GTEST_SKIP() << "cblas_zscal is not exported by the OpenBLAS DLL";
    }
    cblas_zscal(1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZswap) {
    if (rindow_load_libopenblas_func("cblas_zswap") == nullptr) {
        GTEST_SKIP() << "cblas_zswap is not exported by the OpenBLAS DLL";
    }
    cblas_zswap(1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZsymm) {
    if (rindow_load_libopenblas_func("cblas_zsymm") == nullptr) {
        GTEST_SKIP() << "cblas_zsymm is not exported by the OpenBLAS DLL";
    }
    cblas_zsymm(CblasRowMajor, CblasLeft, CblasUpper, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZsyr2k) {
    if (rindow_load_libopenblas_func("cblas_zsyr2k") == nullptr) {
        GTEST_SKIP() << "cblas_zsyr2k is not exported by the OpenBLAS DLL";
    }
    cblas_zsyr2k(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZsyrk) {
    if (rindow_load_libopenblas_func("cblas_zsyrk") == nullptr) {
        GTEST_SKIP() << "cblas_zsyrk is not exported by the OpenBLAS DLL";
    }
    cblas_zsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtbmv) {
    if (rindow_load_libopenblas_func("cblas_ztbmv") == nullptr) {
        GTEST_SKIP() << "cblas_ztbmv is not exported by the OpenBLAS DLL";
    }
    cblas_ztbmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtbsv) {
    if (rindow_load_libopenblas_func("cblas_ztbsv") == nullptr) {
        GTEST_SKIP() << "cblas_ztbsv is not exported by the OpenBLAS DLL";
    }
    cblas_ztbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtpmv) {
    if (rindow_load_libopenblas_func("cblas_ztpmv") == nullptr) {
        GTEST_SKIP() << "cblas_ztpmv is not exported by the OpenBLAS DLL";
    }
    cblas_ztpmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtpsv) {
    if (rindow_load_libopenblas_func("cblas_ztpsv") == nullptr) {
        GTEST_SKIP() << "cblas_ztpsv is not exported by the OpenBLAS DLL";
    }
    cblas_ztpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtrmm) {
    if (rindow_load_libopenblas_func("cblas_ztrmm") == nullptr) {
        GTEST_SKIP() << "cblas_ztrmm is not exported by the OpenBLAS DLL";
    }
    cblas_ztrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtrmv) {
    if (rindow_load_libopenblas_func("cblas_ztrmv") == nullptr) {
        GTEST_SKIP() << "cblas_ztrmv is not exported by the OpenBLAS DLL";
    }
    cblas_ztrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtrsm) {
    if (rindow_load_libopenblas_func("cblas_ztrsm") == nullptr) {
        GTEST_SKIP() << "cblas_ztrsm is not exported by the OpenBLAS DLL";
    }
    cblas_ztrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, 1, 1, (void *)double_values, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, CblasZtrsv) {
    if (rindow_load_libopenblas_func("cblas_ztrsv") == nullptr) {
        GTEST_SKIP() << "cblas_ztrsv is not exported by the OpenBLAS DLL";
    }
    cblas_ztrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, 1, (void *)double_values, 1, (void *)double_values, 1);
}

TEST_F(OpenBLASRoutineTest, GotoSetNumThreads) {
    if (rindow_load_libopenblas_func("goto_set_num_threads") == nullptr) {
        GTEST_SKIP() << "goto_set_num_threads is not exported by the OpenBLAS DLL";
    }
    goto_set_num_threads(0);
}

TEST_F(OpenBLASRoutineTest, OpenblasGetConfig) {
    if (rindow_load_libopenblas_func("openblas_get_config") == nullptr) {
        GTEST_SKIP() << "openblas_get_config is not exported by the OpenBLAS DLL";
    }
    openblas_get_config();
}

TEST_F(OpenBLASRoutineTest, OpenblasGetCorename) {
    if (rindow_load_libopenblas_func("openblas_get_corename") == nullptr) {
        GTEST_SKIP() << "openblas_get_corename is not exported by the OpenBLAS DLL";
    }
    openblas_get_corename();
}

TEST_F(OpenBLASRoutineTest, OpenblasGetNumProcs) {
    if (rindow_load_libopenblas_func("openblas_get_num_procs") == nullptr) {
        GTEST_SKIP() << "openblas_get_num_procs is not exported by the OpenBLAS DLL";
    }
    openblas_get_num_procs();
}

TEST_F(OpenBLASRoutineTest, OpenblasGetNumThreads) {
    if (rindow_load_libopenblas_func("openblas_get_num_threads") == nullptr) {
        GTEST_SKIP() << "openblas_get_num_threads is not exported by the OpenBLAS DLL";
    }
    openblas_get_num_threads();
}

TEST_F(OpenBLASRoutineTest, OpenblasGetParallel) {
    if (rindow_load_libopenblas_func("openblas_get_parallel") == nullptr) {
        GTEST_SKIP() << "openblas_get_parallel is not exported by the OpenBLAS DLL";
    }
    openblas_get_parallel();
}

TEST_F(OpenBLASRoutineTest, OpenblasSetNumThreads) {
    if (rindow_load_libopenblas_func("openblas_set_num_threads") == nullptr) {
        GTEST_SKIP() << "openblas_set_num_threads is not exported by the OpenBLAS DLL";
    }
    openblas_set_num_threads(0);
}

TEST_F(OpenBLASRoutineTest, OpenblasSetNumThreadsLocal) {
    if (rindow_load_libopenblas_func("openblas_set_num_threads_local") == nullptr) {
        GTEST_SKIP() << "openblas_set_num_threads_local is not exported by the OpenBLAS DLL";
    }
    openblas_set_num_threads_local(0);
}

TEST_F(OpenBLASRoutineTest, OpenblasSetThreadsCallbackFunction) {
    if (rindow_load_libopenblas_func("openblas_set_threads_callback_function") == nullptr) {
        GTEST_SKIP() << "openblas_set_threads_callback_function is not exported by the OpenBLAS DLL";
    }
    openblas_set_threads_callback_function(0);
}

TEST_F(OpenBLASRoutineTest, SaxpyComputesExpectedResult) {
    const float x[] = {1.0f, 2.0f, 3.0f};
    float y[] = {10.0f, 20.0f, 30.0f};
    if (rindow_load_libopenblas_func("cblas_saxpy") == nullptr) {
        GTEST_SKIP() << "cblas_saxpy is not exported by the OpenBLAS DLL";
    }
    cblas_saxpy(3, 2.0f, x, 1, y, 1);
    EXPECT_FLOAT_EQ(12.0f, y[0]);
    EXPECT_FLOAT_EQ(24.0f, y[1]);
    EXPECT_FLOAT_EQ(36.0f, y[2]);
}
