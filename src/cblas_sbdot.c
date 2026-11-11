#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sbdot not found\n";
typedef float (CALLBACK* PFNcblas_sbdot)( /* cblas_sbdot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST bfloat16 *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST bfloat16 *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sbdot _g_cblas_sbdot = NULL;
float cblas_sbdot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST bfloat16 *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST bfloat16 *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sbdot==NULL) {
        _g_cblas_sbdot = rindow_load_libopenblas_func("cblas_sbdot"); 
        if(_g_cblas_sbdot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_sbdot(
        n,
        x,
        incx,
        y,
        incy    
    );
}
