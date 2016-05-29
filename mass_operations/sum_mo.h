#pragma once
//@prevline
#include "../base.h"
//@prevline
template<typename T> struct SumMO {
	typedef T Value;
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return lhs + rhs;
	}
	
	Value chain (pass(Value) lhs, pass(Value) rhs) {
		return lhs + rhs;
	}
	
	Value reverse (pass(Value) val) {
		return -val;
	}
};
//@prevline
//@prevline