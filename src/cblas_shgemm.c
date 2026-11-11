#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_shgemm not found\n";
typedef void (CALLBACK* PFNcblas_shgemm)( /* cblas_shgemm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST hfloat16 *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST hfloat16 *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_shgemm _g_cblas_shgemm = NULL;
void cblas_shgemm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST hfloat16 *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST hfloat16 *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST float            beta,
    float *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_shgemm==NULL) {
        _g_cblas_shgemm = rindow_load_libopenblas_func("cblas_shgemm"); 
        if(_g_cblas_shgemm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_shgemm(
        Order,
        TransA,
        TransB,
        M,
        N,
        K,
        alpha,
        A,
        lda,
        B,
        ldb,
        beta,
        C,
        ldc    
    );
}
