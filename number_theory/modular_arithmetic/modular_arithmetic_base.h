#pragma once
//@prevline
#include "../extended_gcd.h"
//@prevline
template<MODAR_TYPE mod> class MODAR_CLASSNAME {
private:

	/**
	* abs(value) should not be greater than mod
	*/
	MODAR_TYPE value;
	
	static_assert(mod > 0, "Mod has to be positive");
	
	MODAR_CLASSNAME (MODAR_TYPE val, int) : value(val) {}
	
public:
	MODAR_CLASSNAME () : value(0) {}
	#ifndef MODAR_LONG
	MODAR_CLASSNAME (int val) : value(val % mod) {}
	#endif
	MODAR_CLASSNAME (ll val) : value(val % mod) {}
	
	/**
	* No normalization performed
	*/
	static MODAR_CLASSNAME interpret (MODAR_TYPE val) {
		return MODAR_CLASSNAME(val, 0);
	}

	bool operator== (MODAR_CLASSNAME rhs) {
		return (value - rhs.value) % mod == 0;
	}
	
	MODAR_CLASSNAME &operator+= (MODAR_CLASSNAME rhs) {
		value += rhs.value;
		if (value > 0) {
			value -= mod;
		} else {
			value += mod;
		}
		return *this;
	}
	
	MODAR_CLASSNAME &operator-= (MODAR_CLASSNAME rhs) {
		value -= rhs.value;
		if (value > 0) {
			value -= mod;
		} else {
			value += mod;
		}
		return *this;
	}
	
	MODAR_CLASSNAME &operator*= (MODAR_CLASSNAME rhs) {
		#ifdef MODAR_LONG
		ll k = ll(ld(value) * rhs.value / mod);
		value = ll(value) * ll(rhs.value) - k * mod;
		#else
		value = ll(value) * ll(rhs.value) % mod;
		#endif
		return *this;
	}
	
	MODAR_CLASSNAME operator- () const {
		return interpret(-value);
	}
	
	MODAR_CLASSNAME &operator/= (MODAR_CLASSNAME rhs) {
		return *this *= rhs.inversed();
	}
	
	MODAR_CLASSNAME inversed () const {
		MODAR_TYPE x, y;
		MODAR_TYPE d = extendedGcd(value, mod, x, y);
		(void)d;
		lib_assert(d == 1);		
		return interpret(x);
	}
	
	MODAR_TYPE int_value () const {
		return (value + mod) % mod;
	}
	
	MODAR_TYPE raw_value () const {
		return value;
	}
};

template<MODAR_TYPE mod> bool operator!= (MODAR_CLASSNAME<mod> lhs, MODAR_CLASSNAME<mod> rhs) {
	return !(lhs == rhs);
}

template<MODAR_TYPE mod> MODAR_CLASSNAME<mod> operator+ (MODAR_CLASSNAME<mod> lhs, MODAR_CLASSNAME<mod> rhs) {
	return lhs += rhs;
}

template<MODAR_TYPE mod> MODAR_CLASSNAME<mod> operator- (MODAR_CLASSNAME<mod> lhs, MODAR_CLASSNAME<mod> rhs) {
	return lhs -= rhs;
}

template<MODAR_TYPE mod> MODAR_CLASSNAME<mod> operator* (MODAR_CLASSNAME<mod> lhs, MODAR_CLASSNAME<mod> rhs) {
	return lhs *= rhs;
}

template<MODAR_TYPE mod> MODAR_CLASSNAME<mod> operator/ (MODAR_CLASSNAME<mod> lhs, MODAR_CLASSNAME<mod> rhs) {
	return lhs /= rhs;
}

template<MODAR_TYPE mod> std::ostream &operator<< (std::ostream &stream, MODAR_CLASSNAME<mod> zn) {
	return stream << zn.int_value();
}

template<MODAR_TYPE mod> std::istream &operator>> (std::istream &stream, MODAR_CLASSNAME<mod> &zn) {
	ll value;
	stream >> value;
	zn = MODAR_CLASSNAME<mod>(value);
	return stream;
}
//@prevline
//@prevline