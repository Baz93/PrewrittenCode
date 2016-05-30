#pragma once
//@prevline
#include "../base.h"
//@prevline
/**
* ax + by = result
*/
template<typename T> T extendedGcd(pass(T) a, pass(T) b, T &x, T &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T d = extendedGcd(b % a, a, y, x);
	x -= (b / a) * y;
	return d;
}
//@prevline
//@prevline