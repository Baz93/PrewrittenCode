#pragma once
//@prevline
template<typename T> T gcd (T a, T b) {
	while (a) {
		swap(a, b);
		a %= b;
	}
	return b;
}

