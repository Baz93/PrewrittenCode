#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename MO> class BackwardsMO {
public:
	typedef typename MO::Value Value;
	typedef typename MO::Argument Argument;
	int n;

private:
	MO mo;

public:
	BackwardsMO (pass(MO) mo_struct, int sz = 0) : mo(mo_struct), n(sz) {}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return mo.unite(rhs, lhs);
	}
	
	Value &set_unite_l (Value &rhs, pass(Value) lhs) {
		return mo.set_unite_r(rhs, lhs);
	}
	
	Value &set_unite_r (Value &lhs, pass(Value)) {
		return mo.set_unite_l(lhs, rhs);
	}
	
	Value neutral () {
		return mo.neutral();
	}
	
	Value reverse (pass(Argument) val) {
		return mo.reverse(val);
	}
	
	Value single (pass(Argument) val) {
		return mo.single(val);
	}
	
	Value single (pass(Argument) val, int pos) {
		return mo.single(val, pos);
	}
	
	Value segment (pass(Argument) val, int cnt) {
		return mo.segment(val, cnt);
	}
	
	Value segment (pass(Argument) val, int l, int r) {
		return mo.segment(val, n - r, n - l);
	}
};
//@prevline
//@prevline