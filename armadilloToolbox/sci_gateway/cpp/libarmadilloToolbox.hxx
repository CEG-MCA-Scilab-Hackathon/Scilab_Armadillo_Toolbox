#ifndef __LIBARMADILLOTOOLBOX_GW_HXX__
#define __LIBARMADILLOTOOLBOX_GW_HXX__

#ifdef _MSC_VER
#ifdef LIBARMADILLOTOOLBOX_GW_EXPORTS
#define LIBARMADILLOTOOLBOX_GW_IMPEXP __declspec(dllexport)
#else
#define LIBARMADILLOTOOLBOX_GW_IMPEXP __declspec(dllimport)
#endif
#else
#define LIBARMADILLOTOOLBOX_GW_IMPEXP
#endif

extern "C" LIBARMADILLOTOOLBOX_GW_IMPEXP int libarmadilloToolbox(wchar_t* _pwstFuncName);









#endif /* __LIBARMADILLOTOOLBOX_GW_HXX__ */
