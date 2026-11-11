#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_set_threads_callback_function not found\n";
typedef void (CALLBACK* PFNopenblas_set_threads_callback_function)( /* openblas_set_threads_callback_function */
    openblas_threads_callback            /* callback */
);
static PFNopenblas_set_threads_callback_function _g_openblas_set_threads_callback_function = NULL;
void openblas_set_threads_callback_function(
    openblas_threads_callback            callback
)
{
    if(_g_openblas_set_threads_callback_function==NULL) {
        _g_openblas_set_threads_callback_function = rindow_load_libopenblas_func("openblas_set_threads_callback_function"); 
        if(_g_openblas_set_threads_callback_function==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_openblas_set_threads_callback_function(
        callback    
    );
}
