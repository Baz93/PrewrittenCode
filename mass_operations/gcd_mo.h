#pragma once
//@prevline
#include "number_theory/gcd.h"
//@prevline
template<typename T> class GcdMO {
public:
	typedef T Value;
	typedef T Argument;
	
private:
	Value zero;
	
public:
	GcdMO (pass(Value) zero_val = Value()) : zero(zero_val) {}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return gcd(lhs, rhs);
	}
	
	Value &set_unite_l (Value &rhs, pass(Value) lhs) {
		return rhs = unite(lhs, rhs);
	}
	
	Value &set_unite_r (Value &lhs, pass(Value) rhs) {
		return lhs = unite(lhs, rhs);
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