#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_crotg not found\n";
typedef void (CALLBACK* PFNcblas_crotg)( /* cblas_crotg */
    void *            /* a */,
    void *            /* b */,
    float *            /* c */,
    void *            /* s */
);
static PFNcblas_crotg _g_cblas_crotg = NULL;
void cblas_crotg(
    void *            a,
    void *            b,
    float *            c,
    void *            s
)
{
    if(_g_cblas_crotg==NULL) {
        _g_cblas_crotg = rindow_load_libopenblas_func("cblas_crotg"); 
        if(_g_cblas_crotg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_crotg(
        a,
        b,
        c,
        s    
    );
}
