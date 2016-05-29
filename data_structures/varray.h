#pragma once
//@prevline
#include "../base.h"
#include "../lib_assert.h"
//@prevline
template<typename T, int N = -1> class Varray : private array<T, N> {
private:
	int n;
	
public:
	T &operator[] (int i) {
		lib_assert(i >= 0);
		lib_assert(i < size());
		return array<T, N>::operator[](i);
	}
	
	const T &operator[] (int i) const {
		lib_assert(i >= 0);
		lib_assert(i < size());
		return array<T, N>::operator[](i);
	}
	
	int size () const {
		return n;
	}
	
	void resize (int s) const {
		lib_assert(s >= 0);
		lib_assert(s <= N);
		return n = size;
	}
};

template<typename T> class Varray<T, -1> : private ve<T> {
public:
	T &operator[] (int i) {
		lib_assert(i >= 0);
		lib_assert(i < size());
		return vector<T>::operator[](i);
	}
	
	const T &operator[] (int i) const {
		lib_assert(i >= 0);
		lib_assert(i < size());
		return vector<T>::operator[](i);
	}
	
	int size () const {
		return int(vector<T>::size());
	}
	
	void resize (int s) const {
		lib_assert(s >= 0);
		vector<T>::resize(s);
	}
};
//@prevline
//@prevline