#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename T> class XorMO {
public:
	typedef T Value;
	
private:
	Value zero;
	
public:
	XorMO (pass(Value) zero_val = Value()) : zero(zero_val) {}
	
	Value neutral () {
		return zero;
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return lhs ^ rhs;
	}
	
	Value reverse (pass(Value) val) {
		return val;
	}
};
//@prevline
//@prevline