#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename T> class MaxMO {
public:
	typedef T Value;
	typedef T Argument;
	
private:
	Value zero;
	
public:
	MaxMO (pass(Value) zero_val = numeric_limits<Value>::min()) : zero(zero_val) {}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return max(lhs, rhs);
	}
	
	Value &set_unite_l (Value &rhs, pass(Value) lhs) {
		umx(rhs, lhs);
		return rhs;
	}
	
	Value &set_unite_r (Value &lhs, pass(Value) rhs) {
		umx(lhs, rhs);
		return lhs;
	}
	
	Value neutral () {
		return zero;
	}
	
	Value single (pass(Argument) val) {
		return val;
	}
	
	Value single (pass(Argument) val, int) {
		return single(val);
	}
	
	Value segment (pass(Argument) val, int cnt) {
		if (cnt) {
			return single(val);
		}
		return neutral();
	}
	
	Value segment (pass(Argument) val, int r, int l) {
		return segment(val, r - l);
	}
};
//@prevline
//@prevline