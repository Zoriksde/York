#pragma once

#ifdef YK_PLATFORM_WINDOWS
	#ifdef YK_BUILD_DLL
		#define YK_API __declspec(dllexport)
	#else
		#define YK_API __declspec(dllimport)
	#endif
#else
	#error York Engine only supports Windows 
#endif