#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename MO> class AddUpdate {
public:
	typedef typename MO::Value Update;
	typedef typename MO::Value Value;
	
private:
	private MO mo;
	
public:
	AddUpdate (pass(MO) mo_struct) : mo(mo_struct) {}
	
	Update unite (pass(Update) lhs, pass(Update) rhs) {
		return mo.unite(lhs, rhs);
	}
	
	Update &set_unite_l (Update &rhs, pass(Update) lhs) {
		return mo.set_unite_l(rhs, lhs);
	}
	
	Update &set_unite_r (Update &lhs, pass(Update) rhs) {
		return mo.set_unite_r(lhs, rhs);
	}
	
	Value apply (pass(Update) lhs, pass(Value) rhs, int cnt) {
		return mo.unite(segment(lhs, cnt), rhs);
	}
	
	Value apply (pass(Update) lhs, pass(Value) rhs, int l, int r) {
		return apply(lhs, rhs, r - l);
	}
	
	Value &set_apply (pass(Update) lhs, Value &rhs, int cnt) {
		return rhs.set_unite_l(segment(lhs, cnt));
	}
	
	Value &set_apply (pass(Update) lhs, Value &rhs, int l, int r) {
		return set_apply(lhs, rhs, r - l);
	}
};
//@prevline
//@prevline