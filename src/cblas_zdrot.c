#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zdrot not found\n";
typedef void (CALLBACK* PFNcblas_zdrot)( /* cblas_zdrot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST double            /* c */,
    OPENBLAS_CONST double            /* s */
);
static PFNcblas_zdrot _g_cblas_zdrot = NULL;
void cblas_zdrot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST double            c,
    OPENBLAS_CONST double            s
)
{
    if(_g_cblas_zdrot==NULL) {
        _g_cblas_zdrot = rindow_load_libopenblas_func("cblas_zdrot"); 
        if(_g_cblas_zdrot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zdrot(
        n,
        x,
        incx,
        y,
        incY,
        c,
        s    
    );
}
