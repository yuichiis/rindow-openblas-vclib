#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cgemm_batch not found\n";
typedef void (CALLBACK* PFNcblas_cgemm_batch)( /* cblas_cgemm_batch */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransA_array */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            /* TransB_array */,
    OPENBLAS_CONST blasint *            /* M_array */,
    OPENBLAS_CONST blasint *            /* N_array */,
    OPENBLAS_CONST blasint *            /* K_array */,
    OPENBLAS_CONST void *            /* alpha_array */,
    OPENBLAS_CONST void * *            /* A_array */,
    OPENBLAS_CONST blasint *            /* lda_array */,
    OPENBLAS_CONST void * *            /* B_array */,
    OPENBLAS_CONST blasint *            /* ldb_array */,
    OPENBLAS_CONST void *            /* beta_array */,
    void * *            /* C_array */,
    OPENBLAS_CONST blasint *            /* ldc_array */,
    OPENBLAS_CONST blasint            /* group_count */,
    OPENBLAS_CONST blasint *            /* group_size */
);
static PFNcblas_cgemm_batch _g_cblas_cgemm_batch = NULL;
void cblas_cgemm_batch(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransA_array,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE *            TransB_array,
    OPENBLAS_CONST blasint *            M_array,
    OPENBLAS_CONST blasint *            N_array,
    OPENBLAS_CONST blasint *            K_array,
    OPENBLAS_CONST void *            alpha_array,
    OPENBLAS_CONST void * *            A_array,
    OPENBLAS_CONST blasint *            lda_array,
    OPENBLAS_CONST void * *            B_array,
    OPENBLAS_CONST blasint *            ldb_array,
    OPENBLAS_CONST void *            beta_array,
    void * *            C_array,
    OPENBLAS_CONST blasint *            ldc_array,
    OPENBLAS_CONST blasint            group_count,
    OPENBLAS_CONST blasint *            group_size
)
{
    if(_g_cblas_cgemm_batch==NULL) {
        _g_cblas_cgemm_batch = rindow_load_libopenblas_func("cblas_cgemm_batch"); 
        if(_g_cblas_cgemm_batch==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cgemm_batch(
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
