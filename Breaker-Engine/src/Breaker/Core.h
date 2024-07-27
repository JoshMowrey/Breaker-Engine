#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#ifdef BR_BUILD_DLL
		#define BREAKER_API __declspec(dllexport)
	#else
		#define BREAKER_API __declspec(dllexport)
	#endif
#else 
	#error Windows Only
#endif

#define BIT(x) (1 << x)
