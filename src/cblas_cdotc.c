#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cdotc not found\n";
typedef openblas_complex_float (CALLBACK* PFNcblas_cdotc)( /* cblas_cdotc */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_cdotc _g_cblas_cdotc = NULL;
openblas_complex_float cblas_cdotc(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_cdotc==NULL) {
        _g_cblas_cdotc = rindow_load_libopenblas_func("cblas_cdotc"); 
        if(_g_cblas_cdotc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            openblas_complex_float result = {0};
            return result;
        }
    }
    return _g_cblas_cdotc(
        n,
        x,
        incx,
        y,
        incy    
    );
}
