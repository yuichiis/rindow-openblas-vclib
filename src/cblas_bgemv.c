#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_bgemv not found\n";
typedef void (CALLBACK* PFNcblas_bgemv)( /* cblas_bgemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* trans */,
    OPENBLAS_CONST blasint            /* m */,
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST bfloat16            /* alpha */,
    OPENBLAS_CONST bfloat16 *            /* a */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST bfloat16 *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST bfloat16            /* beta */,
    bfloat16 *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_bgemv _g_cblas_bgemv = NULL;
void cblas_bgemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            trans,
    OPENBLAS_CONST blasint            m,
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST bfloat16            alpha,
    OPENBLAS_CONST bfloat16 *            a,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST bfloat16 *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST bfloat16            beta,
    bfloat16 *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_bgemv==NULL) {
        _g_cblas_bgemv = rindow_load_libopenblas_func("cblas_bgemv"); 
        if(_g_cblas_bgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_bgemv(
        order,
        trans,
        m,
        n,
        alpha,
        a,
        lda,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
