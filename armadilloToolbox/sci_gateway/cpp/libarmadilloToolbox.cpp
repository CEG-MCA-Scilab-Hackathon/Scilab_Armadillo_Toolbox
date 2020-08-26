#include <wchar.h>
#include "libarmadilloToolbox.hxx"
extern "C"
{
#include "libarmadilloToolbox.h"
#include "addfunction.h"
}

#define MODULE_NAME L"libarmadilloToolbox"

int libarmadilloToolbox(wchar_t* _pwstFuncName)
{
    if(wcscmp(_pwstFuncName, L"armaMatFunc") == 0){ addCFunction(L"armaMatFunc", &armadilloMatFunc, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaMat") == 0){ addCFunction(L"armaMat", &armadilloMat, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaVec") == 0){ addCFunction(L"armaVec", &armadilloVecFunc, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaStat") == 0){ addCFunction(L"armaStat", &armadilloStatistics, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaClust") == 0){ addCFunction(L"armaClust", &armadilloCluster, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaImage") == 0){ addCFunction(L"armaImage", &armadilloImage, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"armaDenseMat") == 0){ addCFunction(L"armaDenseMat", &armadilloDenseMat, MODULE_NAME); }

    return 1;
}
