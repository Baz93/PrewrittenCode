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
//@prevline
#define pass(T) typename PassArgument<T>::Type
//@prevline
//@prevline