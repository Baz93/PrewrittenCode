#pragma once
//@prevline
#include "template.h"
//@prevline
template<typename T> struct PassArgument {
	typedef conditional<
		(//@prevline
			is_trivially_copyable<T>::value && //@prevline
			sizeof(T) <= 12//@prevline
		), //@prevline
		T, const T &//@prevline
	> Type;//@prevline
};
//@prevline
#define pass(T) PassArgument<T>::Type
//@prevline
//@prevline