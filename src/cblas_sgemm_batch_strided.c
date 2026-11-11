#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sgemm_batch_strided not found\n";
typedef void (CALLBACK* PFNcblas_sgemm_batch_strided)( /* cblas_sgemm_batch_strided */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST blasint            /* stridea */,
    OPENBLAS_CONST float *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST blasint            /* strideb */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */,
    OPENBLAS_CONST blasint            /* stridec */,
    OPENBLAS_CONST blasint            /* group_size */
);
static PFNcblas_sgemm_batch_strided _g_cblas_sgemm_batch_strided = NULL;
void cblas_sgemm_batch_strided(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST blasint            stridea,
    OPENBLAS_CONST float *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST blasint            strideb,
    OPENBLAS_CONST float            beta,
    float *            C,
    OPENBLAS_CONST blasint            ldc,
    OPENBLAS_CONST blasint            stridec,
    OPENBLAS_CONST blasint            group_size
)
{
    if(_g_cblas_sgemm_batch_strided==NULL) {
        _g_cblas_sgemm_batch_strided = rindow_load_libopenblas_func("cblas_sgemm_batch_strided"); 
        if(_g_cblas_sgemm_batch_strided==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sgemm_batch_strided(
        Order,
        TransA,
        TransB,
        M,
        N,
        K,
        alpha,
        A,
        lda,
        stridea,
        B,
        ldb,
        strideb,
        beta,
        C,
        ldc,
        stridec,
        group_size    
    );
}
