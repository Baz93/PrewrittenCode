#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename T> class SumMO {
public:
	typedef T Value;
	
private:
	Value zero;
	
public:
	SumMO (pass(Value) zero_val = Value()) : zero(zero_val) {}
	
	Value neutral () {
		return zero;
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return lhs + rhs;
	}
	
	Value reverse (pass(Value) val) {
		return -val;
	}
};
//@prevline
//@prevline