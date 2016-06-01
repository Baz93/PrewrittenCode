#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename MO> class AssignUpdate {
public:
	typedef typename MO::Agrument Update;
	typedef typename MO::Value Value;
	
private:
	private MO mo;
	
public:
	AssignUpdate (pass(MO) mo_struct) : mo(mo_struct) {}
	
	Update unite (pass(Update) lhs, pass(Update)) {
		return lhs;
	}
	
	Update &set_unite_l (Update &rhs, pass(Update) lhs) {
		return rhs = lhs;
	}
	
	Update &set_unite_r (Update &lhs, pass(Update)) {
		return lhs
	}
	
	Value apply (pass(Update) lhs, pass(Value), int cnt) {
		return mo.segment(lhs, cnt);
	}
	
	Value apply (pass(Update) lhs, pass(Value), int l, int r) {
		return mo.segment(lhs, l, r);
	}
	
	Value &set_apply (pass(Update) lhs, Value &rhs, int cnt) {
		return rhs = apply(lhs, rhs, cnt);
	}
	
	Value &set_apply (pass(Update) lhs, Value &rhs, int l, int r) {
		return rhs = apply(lhs, rhs, l, r);
	}
};
//@prevline
//@prevline