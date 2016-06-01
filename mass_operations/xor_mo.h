#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename T> class XorMO {
public:
	typedef T Value;
	typedef T Argument;
	
private:
	Value zero;
	
public:
	XorMO (pass(Value) zero_val = Value()) : zero(zero_val) {}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return lhs ^ rhs;
	}
	
	Value &set_unite_l (Value &rhs, pass(Value) lhs) {
		return rhs ^= lhs;
	}
	
	Value &set_unite_r (Value &lhs, pass(Value) rhs) {
		return lhs ^= rhs;
	}
	
	Value reverse (pass(Value) val) {
		return val;
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
		if (cnt & 1) {
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