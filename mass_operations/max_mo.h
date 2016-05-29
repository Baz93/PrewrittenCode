#pragma once
//@prevline
#include "../base.h"
//@prevline
template<typename T> class MaxMO {
public:
	typedef T Value;
	
private:
	Value zero;
	
public:
	MaxMO (Value zero_val = numeric_limits<Value>::min()) : zero(zero_val) {}
	
	Value neutral () {
		return zero;
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return max(lhs, rhs);
	}
};
//@prevline
//@prevline