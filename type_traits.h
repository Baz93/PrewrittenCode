#pragma once
//@prevline
#include "template.h"
//@prevline
template<typename T> struct PassArgument {
	typedef typename conditional<
		(//@prevline
			is_trivially_copyable<T>::value && //@prevline
			sizeof(T) <= 12//@prevline
		), //@prevline
		T, const T &//@prevline
	>::type Type;//@prevline
};
template<typename T> T common_argument (initializer_list<T> args) {return declval<T>();}

#define pass(T) typename PassArgument<T>::Type
#define basetype(...) decltype(common_argument({__VA_ARGS__}))
//@prevline
//@prevline