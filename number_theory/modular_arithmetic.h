#pragma once
//@prevline
#include "extended_gcd.h"
//@prevline
template<int mod> class ModularArithmetic {
private:

	/**
	* abs(value) should not be greater than mod
	*/
	int value;
	
	static_assert(mod > 0, "Mod has to be positive");
	
	ModularArithmetic (int val, int) : value(val) {}
	
public:
	ModularArithmetic () : value(0) {}
	ModularArithmetic (int val) : value(val % mod) {}
	ModularArithmetic (ll val) : value(val % mod) {}
	
	/**
	* No normalization performed
	*/
	static ModularArithmetic interpret (int val) {
		return ModularArithmetic(val, 0);
	}

	bool operator== (ModularArithmetic rhs) {
		return (value - rhs.value) % mod == 0;
	}
	
	ModularArithmetic &operator+= (ModularArithmetic rhs) {
		value += rhs.value;
		if (value > 0) {
			value -= mod;
		} else {
			value += mod;
		}
		return *this;
	}
	
	ModularArithmetic &operator-= (ModularArithmetic rhs) {
		value -= rhs.value;
		if (value > 0) {
			value -= mod;
		} else {
			value += mod;
		}
		return *this;
	}
	
	ModularArithmetic &operator*= (ModularArithmetic rhs) {
		value = ll(value) * ll(rhs.value) % mod;
		return *this;
	}
	
	ModularArithmetic operator- () const {
		return interpret(-value);
	}
	
	ModularArithmetic &operator/= (ModularArithmetic rhs) {
		return *this *= rhs.inversed();
	}
	
	ModularArithmetic inversed () const {
		int x, y;
		int d = extendedGcd(value, mod, x, y);
		(void)d;
		lib_assert(d == 1);		
		return interpret(x);
	}
	
	int int_value () const {
		return (value + mod) % mod;
	}
	
	int raw_value () const {
		return value;
	}
};

template<int mod> bool operator!= (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return !(lhs == rhs);
}

template<int mod> ModularArithmetic<mod> operator+ (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return lhs += rhs;
}

template<int mod> ModularArithmetic<mod> operator- (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return lhs -= rhs;
}

template<int mod> ModularArithmetic<mod> operator* (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return lhs *= rhs;
}

template<int mod> ModularArithmetic<mod> operator/ (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return lhs /= rhs;
}

template<int mod> std::ostream &operator<< (std::ostream &stream, ModularArithmetic<mod> zn) {
	return stream << zn.int_value();
}

template<int mod> std::istream &operator>> (std::istream &stream, ModularArithmetic<mod> &zn) {
	ll value;
	stream >> value;
	zn = ModularArithmetic<mod>(value);
	return stream;
}
//@prevline
//@prevline