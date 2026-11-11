#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sbstobf16 not found\n";
typedef void (CALLBACK* PFNcblas_sbstobf16)( /* cblas_sbstobf16 */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* in */,
    OPENBLAS_CONST blasint            /* incin */,
    bfloat16 *            /* out */,
    OPENBLAS_CONST blasint            /* incout */
);
static PFNcblas_sbstobf16 _g_cblas_sbstobf16 = NULL;
void cblas_sbstobf16(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            in,
    OPENBLAS_CONST blasint            incin,
    bfloat16 *            out,
    OPENBLAS_CONST blasint            incout
)
{
    if(_g_cblas_sbstobf16==NULL) {
        _g_cblas_sbstobf16 = rindow_load_libopenblas_func("cblas_sbstobf16"); 
        if(_g_cblas_sbstobf16==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sbstobf16(
        n,
        in,
        incin,
        out,
        incout    
    );
}
