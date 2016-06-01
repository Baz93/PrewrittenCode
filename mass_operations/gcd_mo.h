#pragma once
//@prevline
#include "number_theory/gcd.h"
//@prevline
template<typename T> class GcdMO {
public:
	typedef T Value;
	
private:
	Value zero;
	
public:
	GcdMO (pass(Value) zero_val = Value()) : zero(zero_val) {}
	
	Value neutral () {
		return zero;
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return gcd(lhs, rhs);
	}
};
//@prevline
//@prevline