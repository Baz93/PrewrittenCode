#pragma once
//@prevline
#include "data_structures/varray.h" 
//@prevline
template<typename MO, int N> class Fenwick {
private:
	MO mo;
	Varray<typename MO::Value, N> a;
	
public:
	void initialize (int n, pass(MO) mo_struct = MO()) {
		mo = mo_struct;
		a.resize(n);
		forn (i, n) {
			a[i] = mo.neutral();
		}
	}
	
	void add (int i, pass(typename MO::Value) val) {
		lib_assert(i >= 0);
		lib_assert(i < sz(a));
		for	(; i < n; i |= i + 1) {
			a[i] = mo.unite(a[i], val);
		}
	}
	
	typename MO::Value get (int i) {
		lib_assert(i >= 0);
		lib_assert(i <= sz(a));
		typename MO::Value res = mo.neutral();
		for (; i; i &= i - 1) {
			res = mo.unite(res, a[i - 1]);
		}
		return res;
	}
	
	typename MO::Value get (int l, int r) {
		return mo.unite(mo.reverse(get(l)), get(r));
	}
	
	typename MO::Value get_fit (int l, int r) {
		lib_assert(l >= 0);
		lib_assert(l <= r);
		lib_assert(r <= sz(a));
		typename MO::Value res = mo.neutral();
		while (r) {
			int next = r & (r - 1);
			if (next < l) {
				break;
			}
			res = mo.unite(a[r - 1], res);
			r = next;
		}
		return res;
	}
};
//@prevline
//@prevline