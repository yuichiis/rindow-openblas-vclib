#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sbf16tos not found\n";
typedef void (CALLBACK* PFNcblas_sbf16tos)( /* cblas_sbf16tos */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST bfloat16 *            /* in */,
    OPENBLAS_CONST blasint            /* incin */,
    float *            /* out */,
    OPENBLAS_CONST blasint            /* incout */
);
static PFNcblas_sbf16tos _g_cblas_sbf16tos = NULL;
void cblas_sbf16tos(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST bfloat16 *            in,
    OPENBLAS_CONST blasint            incin,
    float *            out,
    OPENBLAS_CONST blasint            incout
)
{
    if(_g_cblas_sbf16tos==NULL) {
        _g_cblas_sbf16tos = rindow_load_libopenblas_func("cblas_sbf16tos"); 
        if(_g_cblas_sbf16tos==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sbf16tos(
        n,
        in,
        incin,
        out,
        incout    
    );
}
