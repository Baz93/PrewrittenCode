#pragma once
//@prevline
#include "../base.h"
//@prevline
template<typename T> class MinMO {
public:
	typedef T Value;
	
private:
	Value zero;
	
public:
	MinMO (Value zero_val = numeric_limits<Value>::max()) : zero(zero_val) {}
	
	Value neutral () {
		return zero;
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return min(lhs, rhs);
	}
};
//@prevline
//@prevline