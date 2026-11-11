#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sbgemm_batch not found\n";
typedef void (CALLBACK* PFNcblas_sbgemm_batch)( /* cblas_sbgemm_batch */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransA_array */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransB_array */,
    OPENBLAS_CONST blasint *            /* M_array */,
    OPENBLAS_CONST blasint *            /* N_array */,
    OPENBLAS_CONST blasint *            /* K_array */,
    OPENBLAS_CONST float *            /* alpha_array */,
    OPENBLAS_CONST bfloat16 * *            /* A_array */,
    OPENBLAS_CONST blasint *            /* lda_array */,
    OPENBLAS_CONST bfloat16 * *            /* B_array */,
    OPENBLAS_CONST blasint *            /* ldb_array */,
    OPENBLAS_CONST float *            /* beta_array */,
    float * *            /* C_array */,
    OPENBLAS_CONST blasint *            /* ldc_array */,
    OPENBLAS_CONST blasint            /* group_count */,
    OPENBLAS_CONST blasint *            /* group_size */
);
static PFNcblas_sbgemm_batch _g_cblas_sbgemm_batch = NULL;
void cblas_sbgemm_batch(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransA_array,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransB_array,
    OPENBLAS_CONST blasint *            M_array,
    OPENBLAS_CONST blasint *            N_array,
    OPENBLAS_CONST blasint *            K_array,
    OPENBLAS_CONST float *            alpha_array,
    OPENBLAS_CONST bfloat16 * *            A_array,
    OPENBLAS_CONST blasint *            lda_array,
    OPENBLAS_CONST bfloat16 * *            B_array,
    OPENBLAS_CONST blasint *            ldb_array,
    OPENBLAS_CONST float *            beta_array,
    float * *            C_array,
    OPENBLAS_CONST blasint *            ldc_array,
    OPENBLAS_CONST blasint            group_count,
    OPENBLAS_CONST blasint *            group_size
)
{
    if(_g_cblas_sbgemm_batch==NULL) {
        _g_cblas_sbgemm_batch = rindow_load_libopenblas_func("cblas_sbgemm_batch"); 
        if(_g_cblas_sbgemm_batch==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sbgemm_batch(
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
