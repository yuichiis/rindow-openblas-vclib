#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cdotu not found\n";
typedef openblas_complex_float (CALLBACK* PFNcblas_cdotu)( /* cblas_cdotu */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_cdotu _g_cblas_cdotu = NULL;
openblas_complex_float cblas_cdotu(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_cdotu==NULL) {
        _g_cblas_cdotu = rindow_load_libopenblas_func("cblas_cdotu"); 
        if(_g_cblas_cdotu==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_cdotu(
        n,
        x,
        incx,
        y,
        incy    
    );
}
