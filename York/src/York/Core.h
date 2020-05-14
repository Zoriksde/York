#pragma once

#ifdef YK_PLATFORM_WINDOWS
	#ifdef YK_BUILD_DLL
		#define YORK_API __declspec(dllexport)
	#else
		#define YORK_API __declspec(dllimport)
	#endif
#else
	#error York Engine only supports Windows 
#endif

#ifdef YK_DEBUG
	#define YK_ENABLE_ASSERTS
#endif

#ifdef YK_ENABLE_ASSERTS 
	#define YK_ASSERT(x, ...) { if(!(x)) { YK_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak();} }
	#define YK_CORE_ASSERT(x, ...) { if(!(x)) { YK_CORE_ERROR("Assertion failed {0}", __VA_ARGS__); __debugbreak();} }
#else 
	#define YK_ASSERT(x, ...) 
	#define YK_CORE_ASSERT(x, ...) 
#endif

#define BIT(x) (1 << x)

#define YK_BIND_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)