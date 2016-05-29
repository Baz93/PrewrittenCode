#pragma once
//@prevline
#ifdef LIB_ASSERT
	#define lib_assert(...) assert(__VA_ARGS__)
#else
	#define lib_assert(...)
#endif
//@prevline
//@prevline