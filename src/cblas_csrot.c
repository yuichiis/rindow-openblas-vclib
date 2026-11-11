#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_csrot not found\n";
typedef void (CALLBACK* PFNcblas_csrot)( /* cblas_csrot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST float            /* c */,
    OPENBLAS_CONST float            /* s */
);
static PFNcblas_csrot _g_cblas_csrot = NULL;
void cblas_csrot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST float            c,
    OPENBLAS_CONST float            s
)
{
    if(_g_cblas_csrot==NULL) {
        _g_cblas_csrot = rindow_load_libopenblas_func("cblas_csrot"); 
        if(_g_cblas_csrot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_csrot(
        n,
        x,
        incx,
        y,
        incY,
        c,
        s    
    );
}
