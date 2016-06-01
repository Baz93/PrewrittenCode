#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename MO> class BackwardsMO {
public:
	typedef typename MO::Value Value;

private:
	MO mo;

public:
	BackwardsMO (pass(MO) mo_struct) : mo(mo_struct) {}
	
	Value neutral () {
		return mo.neutral();
	}
	
	Value unite (pass(Value) lhs, pass(Value) rhs) {
		return mo.unite(rhs, lhs);
	}
	
	Value reverse (pass(Value) val) {
		return mo.reverse(val);
	}
};
//@prevline
//@prevline