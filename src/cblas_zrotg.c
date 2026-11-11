#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zrotg not found\n";
typedef void (CALLBACK* PFNcblas_zrotg)( /* cblas_zrotg */
    void *            /* a */,
    void *            /* b */,
    double *            /* c */,
    void *            /* s */
);
static PFNcblas_zrotg _g_cblas_zrotg = NULL;
void cblas_zrotg(
    void *            a,
    void *            b,
    double *            c,
    void *            s
)
{
    if(_g_cblas_zrotg==NULL) {
        _g_cblas_zrotg = rindow_load_libopenblas_func("cblas_zrotg"); 
        if(_g_cblas_zrotg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zrotg(
        a,
        b,
        c,
        s    
    );
}
