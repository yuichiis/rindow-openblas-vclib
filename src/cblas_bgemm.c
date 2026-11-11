#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_bgemm not found\n";
typedef void (CALLBACK* PFNcblas_bgemm)( /* cblas_bgemm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST bfloat16            /* alpha */,
    OPENBLAS_CONST bfloat16 *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST bfloat16 *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST bfloat16            /* beta */,
    bfloat16 *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_bgemm _g_cblas_bgemm = NULL;
void cblas_bgemm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST bfloat16            alpha,
    OPENBLAS_CONST bfloat16 *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST bfloat16 *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST bfloat16            beta,
    bfloat16 *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_bgemm==NULL) {
        _g_cblas_bgemm = rindow_load_libopenblas_func("cblas_bgemm"); 
        if(_g_cblas_bgemm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_bgemm(
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
