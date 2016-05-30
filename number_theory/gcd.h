#pragma once
//@prevline
#include "base.h"
//@prevline
template<typename T> T gcd (pass(T) a, pass(T) b) {
	while (a) {
		swap(a, b);
		a %= b;
	}
	return b;
}
//@prevline
//@prevline