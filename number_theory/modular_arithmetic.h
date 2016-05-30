#pragma once
//@prevline
#include "extended_gcd.h"
//@prevline
template<int mod> class ModularArithmetic {
private:
	int value;
	
	static_assert(mod > 0, "Mod has to be positive");
	
	ModularArithmetic (int val, int) : value(val) {}
	
public:
	ModularArithmetic () : value(0) {}
	
	ModularArithmetic (int val) : value(val % mod) {
		if (value < 0) {
			value += mod;
		}
	}
	
	ModularArithmetic (ll val) : value(val % mod) {
		if (value < 0) {
			value += mod;
		}
	}
	
	/**
	* No normalization performed
	*/
	static ModularArithmetic rawValue (int val) {
		return ModularArithmetic(val, 0);
	}

	bool operator== (ModularArithmetic rhs) {
		return value == rhs.value;
	}
	
	ModularArithmetic &operator+= (ModularArithmetic rhs) {
		value += rhs.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}
	
	ModularArithmetic &operator-= (ModularArithmetic rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod;
		}
		return *this;
	}
	
	ModularArithmetic &operator*= (ModularArithmetic rhs) {
		ll result = ll(value) * ll(rhs.value);
		value = result % mod;
		return *this;
	}
	
	ModularArithmetic operator- () const {
		if (value == 0) {
			return *this;
		} else {
			return rawValue(mod - value);
		}
	}
	
	ModularArithmetic &operator/= (ModularArithmetic rhs) {
		return *this *= rhs.inversed();
	}
	
	ModularArithmetic inversed () const {
		lib_assert(value != 0);
		
		int x, y;
		int d = extendedGcd(value, mod, x, y);
		(void)d;
		lib_assert(d == 1);
		
		if (x < 0) {
			x += mod;
		}
		return rawValue(x);
	}
	
	int intValue () const {
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
	return stream << zn.intValue();
}

template<int mod> std::istream &operator>> (std::istream &stream, ModularArithmetic<mod> &zn) {
	ll value;
	stream >> value;
	zn = ModularArithmetic<mod>(value);
	return stream;
}
//@prevline
//@prevline