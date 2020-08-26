#include <wchar.h>
#include "libtest_toolbox.hxx"
extern "C"
{
#include "libtest_toolbox.h"
#include "addfunction.h"
}

#define MODULE_NAME L"libtest_toolbox"

int libtest_toolbox(wchar_t* _pwstFuncName)
{
    if(wcscmp(_pwstFuncName, L"genRand2d01") == 0){ addCFunction(L"genRand2d01", &armadilloGenRand2d, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"accumulate") == 0){ addCFunction(L"accumulate", &armadilloAccumulate, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"cummulativeSum") == 0){ addCFunction(L"cummulativeSum", &armadilloCummulativeSum, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"determinant") == 0){ addCFunction(L"determinant", &armadilloDeterminant, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"shuffle") == 0){ addCFunction(L"shuffle", &armadilloShuffle, MODULE_NAME); }

    return 1;
}
