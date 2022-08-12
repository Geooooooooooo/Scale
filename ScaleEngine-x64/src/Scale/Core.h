#pragma once

#ifdef SL_WINDOWS_PLATFORM
	#ifdef SL_BUILD_DLL
		#define SCALE_API __declspec(dllexport)
	#else
		#define SCALE_API __declspec(dllimport)
	#endif 
#else
	#error Scale only supports Windows!
#endif
