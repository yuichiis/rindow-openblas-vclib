#include <Windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <cblas.h>
#include "vclib.h"

static char msg_function_not_found[] = "cblas_xerbla not found\n";

typedef void (CALLBACK* PFNcblas_xerbla)(
    blasint p,
    OPENBLAS_CONST char *rout,
    OPENBLAS_CONST char *form,
    ...
);
static PFNcblas_xerbla _g_cblas_xerbla = NULL;

void cblas_xerbla(
    blasint p,
    OPENBLAS_CONST char *rout,
    OPENBLAS_CONST char *form,
    ...
)
{
    if (_g_cblas_xerbla == NULL) {
        _g_cblas_xerbla = (PFNcblas_xerbla)rindow_load_libopenblas_func("cblas_xerbla");
        if (_g_cblas_xerbla == NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            DWORD written;
            WriteConsoleA(hStdOut, msg_function_not_found,
                          sizeof(msg_function_not_found) - 1, &written, NULL);
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
