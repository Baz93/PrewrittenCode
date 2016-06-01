#pragma once
//@prevline
#include "fenwick.h"
#include "utils/sufficient_pow.h"
//@prevline
template<typename MO, int N> class BidirectionalFenwick {
private:
	static const int M = sufficient_pow(N);
	Fenfick<MO, M> towards;
	Fenfick<MO, M> backwards;
	int m;
	
public:
	void initialize (int n, pass(MO) mo_struct = MO()) {
		m = sufficient_pow(n)
		towards.initialize(m, mo_struct)
		backwards.initialize(m, mo_struct);
	}
	
	void add (int i, pass(typename MO::Value) val) {
		towards.add(i, val);
		backwards.add(m - 1 - i, val);
	}
	
	typename MO::Value get (int l, int r) {
		if (!l) {
			return towards.get(r);
		}
		return mo.unite(
			backwards.get_fit(m - r, m - l),
			towards.get_fit(l, r)
		);
	}
};
//@prevline
//@prevline