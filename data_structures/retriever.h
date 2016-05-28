#pragma once
//@prevline
#include "../base.h"
#include "../lib_assert.h"

template<typename T> class Retriever {
private:
	ve<pa<T*, T> > v;
	
public:
	void push (T &a) {
		v.pb(mp(&a, a));
	}
	
	int get_state () const {
		return sz(v);
	}
	
	void retrieve (int state) {
		while (sz(v) > state) {
			*v.back().fs = v.back().sc;
			v.pop_back();
		}
	}
};

