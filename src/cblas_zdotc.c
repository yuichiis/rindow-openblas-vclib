#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zdotc not found\n";
typedef openblas_complex_double (CALLBACK* PFNcblas_zdotc)( /* cblas_zdotc */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zdotc _g_cblas_zdotc = NULL;
openblas_complex_double cblas_zdotc(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zdotc==NULL) {
        _g_cblas_zdotc = rindow_load_libopenblas_func("cblas_zdotc"); 
        if(_g_cblas_zdotc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_zdotc(
        n,
        x,
        incx,
        y,
        incy    
    );
}
