#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zdotu not found\n";
typedef openblas_complex_double (CALLBACK* PFNcblas_zdotu)( /* cblas_zdotu */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zdotu _g_cblas_zdotu = NULL;
openblas_complex_double cblas_zdotu(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zdotu==NULL) {
        _g_cblas_zdotu = rindow_load_libopenblas_func("cblas_zdotu"); 
        if(_g_cblas_zdotu==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_zdotu(
        n,
        x,
        incx,
        y,
        incy    
    );
}
