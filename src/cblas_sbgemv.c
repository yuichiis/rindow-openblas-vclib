#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sbgemv not found\n";
typedef void (CALLBACK* PFNcblas_sbgemv)( /* cblas_sbgemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* trans */,
    OPENBLAS_CONST blasint            /* m */,
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST bfloat16 *            /* a */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST bfloat16 *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sbgemv _g_cblas_sbgemv = NULL;
void cblas_sbgemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            trans,
    OPENBLAS_CONST blasint            m,
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST bfloat16 *            a,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST bfloat16 *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float            beta,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sbgemv==NULL) {
        _g_cblas_sbgemv = rindow_load_libopenblas_func("cblas_sbgemv"); 
        if(_g_cblas_sbgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sbgemv(
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
