#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
#include <stdarg.h>
#include <stdio.h>
static char msg_function_not_found[]  = "cblas_xerbla not found\n";
typedef void (CALLBACK* PFNcblas_xerbla)( /* cblas_xerbla */
    blasint            /* p */,
    OPENBLAS_CONST char *            /* rout */,
    OPENBLAS_CONST char *            /* form */,
    ...            /*  */
);
static PFNcblas_xerbla _g_cblas_xerbla = NULL;
void cblas_xerbla(
    blasint            p,
    OPENBLAS_CONST char *            rout,
    OPENBLAS_CONST char *            form,
    ...            
)
{
    if(_g_cblas_xerbla==NULL) {
        _g_cblas_xerbla = rindow_load_libopenblas_func("cblas_xerbla"); 
        if(_g_cblas_xerbla==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    char buf[512];
    va_list ap;
    va_start(ap, form);
    vsnprintf(buf, sizeof(buf), form, ap);
    va_end(ap);
    _g_cblas_xerbla(p, rout, "%s", buf);
}
