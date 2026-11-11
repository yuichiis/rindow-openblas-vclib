#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dgemm_batch not found\n";
typedef void (CALLBACK* PFNcblas_dgemm_batch)( /* cblas_dgemm_batch */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransA_array */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransB_array */,
    OPENBLAS_CONST blasint *            /* M_array */,
    OPENBLAS_CONST blasint *            /* N_array */,
    OPENBLAS_CONST blasint *            /* K_array */,
    OPENBLAS_CONST double *            /* alpha_array */,
    OPENBLAS_CONST double * *            /* A_array */,
    OPENBLAS_CONST blasint *            /* lda_array */,
    OPENBLAS_CONST double * *            /* B_array */,
    OPENBLAS_CONST blasint *            /* ldb_array */,
    OPENBLAS_CONST double *            /* beta_array */,
    double * *            /* C_array */,
    OPENBLAS_CONST blasint *            /* ldc_array */,
    OPENBLAS_CONST blasint            /* group_count */,
    OPENBLAS_CONST blasint *            /* group_size */
);
static PFNcblas_dgemm_batch _g_cblas_dgemm_batch = NULL;
void cblas_dgemm_batch(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransA_array,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransB_array,
    OPENBLAS_CONST blasint *            M_array,
    OPENBLAS_CONST blasint *            N_array,
    OPENBLAS_CONST blasint *            K_array,
    OPENBLAS_CONST double *            alpha_array,
    OPENBLAS_CONST double * *            A_array,
    OPENBLAS_CONST blasint *            lda_array,
    OPENBLAS_CONST double * *            B_array,
    OPENBLAS_CONST blasint *            ldb_array,
    OPENBLAS_CONST double *            beta_array,
    double * *            C_array,
    OPENBLAS_CONST blasint *            ldc_array,
    OPENBLAS_CONST blasint            group_count,
    OPENBLAS_CONST blasint *            group_size
)
{
    if(_g_cblas_dgemm_batch==NULL) {
        _g_cblas_dgemm_batch = rindow_load_libopenblas_func("cblas_dgemm_batch"); 
        if(_g_cblas_dgemm_batch==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dgemm_batch(
        Order,
        TransA_array,
        TransB_array,
        M_array,
        N_array,
        K_array,
        alpha_array,
        A_array,
        lda_array,
        B_array,
        ldb_array,
        beta_array,
        C_array,
        ldc_array,
        group_count,
        group_size    
    );
}
