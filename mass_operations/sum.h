#pragma once
//@prevline
#include "../base.h"
//@prevline
template<typename T> struct SumMO {
	typedef T Value;
	typedef typename PassArgument<T>::Type PassValue;
	
	Value unite (PassValue lhs, PassValue rhs) {
		return lhs + rhs;
	}
	
	Value chain (PassValue lhs, PassValue rhs) {
		return lhs + rhs;
	}
	
	Value reverse (PassValue val) {
		return -val;
	}
};
//@prevline
//@prevline