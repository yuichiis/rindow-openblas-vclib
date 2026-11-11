#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dbf16tod not found\n";
typedef void (CALLBACK* PFNcblas_dbf16tod)( /* cblas_dbf16tod */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST bfloat16 *            /* in */,
    OPENBLAS_CONST blasint            /* incin */,
    double *            /* out */,
    OPENBLAS_CONST blasint            /* incout */
);
static PFNcblas_dbf16tod _g_cblas_dbf16tod = NULL;
void cblas_dbf16tod(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST bfloat16 *            in,
    OPENBLAS_CONST blasint            incin,
    double *            out,
    OPENBLAS_CONST blasint            incout
)
{
    if(_g_cblas_dbf16tod==NULL) {
        _g_cblas_dbf16tod = rindow_load_libopenblas_func("cblas_dbf16tod"); 
        if(_g_cblas_dbf16tod==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dbf16tod(
        n,
        in,
        incin,
        out,
        incout    
    );
}
