#pragma once
//@prevline
#include "extended_gcd.h"
//@prevline
template<int mod> class ModularArithmetic {
public:
	ModularArithmetic () : value(0) {}

	/**
	* Instead of ctor, to allow not to normalize in ctor
	*/
	static ModularArithmetic valueOf (int value) {
		int x = value % mod;
		if (x < 0) {
			x += mod;
		}
		return ModularArithmetic(x);
	}

	static ModularArithmetic valueOf (ll value) {
		int x = value % mod;
		if (x < 0) {
			x += mod;
		}
		return ModularArithmetic(x);
	}

	static ModularArithmetic rawValueOf (int value) {
		lib_assert(value >= 0 && value < mod);
		return ModularArithmetic(value);
	}
	ModularArithmetic &operator= (int rhs) {
		return *this = valueOf(rhs);
	}
	ModularArithmetic &operator= (ll rhs) {
		return *this = valueOf(rhs);
	}

	ModularArithmetic &operator+= (ModularArithmetic rhs) {
		value += rhs.value;
		if (value >= mod) {
			value -= mod;
		}
		return *this;
	}
	ModularArithmetic &operator+= (int rhs) {
		return *this += ModularArithmetic::valueOf(rhs);
	}
	ModularArithmetic &operator+= (ll rhs) {
		return *this += ModularArithmetic::valueOf(rhs);
	}

	ModularArithmetic &operator-= (ModularArithmetic rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += mod;
		}
		return *this;
	}
	ModularArithmetic &operator-= (int rhs) {
		return *this -= ModularArithmetic::valueOf(rhs);
	}
	ModularArithmetic &operator-= (ll rhs) {
		return *this -= ModularArithmetic::valueOf(rhs);
	}

	ModularArithmetic &operator*= (ModularArithmetic rhs) {
		ll result = ll(value) * ll(rhs.value);
		value = result % mod;
		return *this;
	}
	ModularArithmetic &operator*= (int rhs) {
		return *this *= ModularArithmetic::valueOf(rhs);
	}
	ModularArithmetic &operator*= (ll rhs) {
		return *this *= ModularArithmetic::valueOf(rhs);
	}

	ModularArithmetic operator- () const {
		if (value == 0) {
			return *this;
		} else {
			return ModularArithmetic(mod - value);
		}
	}

	ModularArithmetic &operator/= (ModularArithmetic rhs) {
		return *this *= rhs.inversed();
	}
	ModularArithmetic &operator/= (int rhs) {
		return *this /= ModularArithmetic::valueOf(rhs);
	}
	ModularArithmetic &operator/= (ll rhs) {
		return *this /= ModularArithmetic::valueOf(rhs);
	}

	bool operator== (ModularArithmetic rhs) const {
		return value == rhs.value;
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
		return ModularArithmetic(x);
	}

	template<int M> friend std::ostream &operator<< (std::ostream &, ModularArithmetic<M> zn);
	template<int M> friend std::istream &operator>> (std::istream &, ModularArithmetic<M> &zn);

	int intValue () const {
		return value;
	}

private:
	/**
	* No normalization performed
	*/
	explicit ModularArithmetic (int val) : value(val) {}

	int value;
	
	static_assert(mod > 0, "Mod has to be positive");
};

template<int mod> bool operator== (ModularArithmetic<mod> lhs, int rhs) {
	return lhs == ModularArithmetic<mod>::valueOf(rhs);
}
template<int mod> bool operator== (int lhs, ModularArithmetic<mod> rhs) {
	return rhs == lhs;
}
template<int mod> bool operator== (ModularArithmetic<mod> lhs, ll rhs) {
	return lhs == ModularArithmetic<mod>::valueOf(rhs);
}
template<int mod> bool operator== (ll lhs, ModularArithmetic<mod> &rhs) {
	return rhs == lhs;
}

template<int mod> bool operator!= (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	return !(lhs == rhs);
}
template<int mod> bool operator!= (ModularArithmetic<mod> lhs, int rhs) {
	return !(lhs == rhs);
}
template<int mod> bool operator!= (int lhs, ModularArithmetic<mod> rhs) {
	return !(lhs == rhs);
}
template<int mod> bool operator!= (ModularArithmetic<mod> lhs, ll rhs) {
	return !(lhs == rhs);
}
template<int mod> bool operator!= (ll rhs, ModularArithmetic<mod> lhs) {
	return !(lhs == rhs);
}

template<int mod> ModularArithmetic<mod> operator+ (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp += rhs;
}
template<int mod> ModularArithmetic<mod> operator+ (ModularArithmetic<mod> lhs, int rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp += rhs;
}
template<int mod> ModularArithmetic<mod> operator+ (int lhs, ModularArithmetic<mod> rhs) {
	return rhs + lhs;
}
template<int mod> ModularArithmetic<mod> operator+ (ModularArithmetic<mod> lhs, ll rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp += rhs;
}
template<int mod> ModularArithmetic<mod> operator+ (ll lhs, ModularArithmetic<mod> rhs) {
	return rhs + lhs;
}

template<int mod> ModularArithmetic<mod> operator- (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp -= rhs;
}
template<int mod> ModularArithmetic<mod> operator- (ModularArithmetic<mod> lhs, int rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp -= rhs;
}
template<int mod> ModularArithmetic<mod> operator- (int lhs, ModularArithmetic<mod> rhs) {
	return ModularArithmetic<mod>::valueOf(lhs) - rhs;
}
template<int mod> ModularArithmetic<mod> operator- (ModularArithmetic<mod> lhs, ll rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp -= rhs;
}
template<int mod> ModularArithmetic<mod> operator- (long lhs, ModularArithmetic<mod> rhs) {
	return ModularArithmetic<mod>::valueOf(lhs) - rhs;
}

template<int mod> ModularArithmetic<mod> operator* (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp *= rhs;
}
template<int mod> ModularArithmetic<mod> operator* (ModularArithmetic<mod> lhs, int rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp *= rhs;
}
template<int mod> ModularArithmetic<mod> operator* (int lhs, ModularArithmetic<mod> rhs) {
	return rhs * lhs;
}
template<int mod> ModularArithmetic<mod> operator* (ModularArithmetic<mod> lhs, ll rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp *= rhs;
}
template<int mod> ModularArithmetic<mod> operator* (ll lhs, ModularArithmetic<mod> rhs) {
	return rhs * lhs;
}

template<int mod> ModularArithmetic<mod> operator/ (ModularArithmetic<mod> lhs, ModularArithmetic<mod> rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp /= rhs;
}
template<int mod> ModularArithmetic<mod> operator/ (ModularArithmetic<mod> lhs, int rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp /= rhs;
}
template<int mod> ModularArithmetic<mod> operator/ (int lhs, ModularArithmetic<mod> rhs) {
	return ModularArithmetic<mod>::valueOf(lhs) / rhs;
}
template<int mod> ModularArithmetic<mod> operator/ (ModularArithmetic<mod> lhs, ll rhs) {
	ModularArithmetic<mod> cp = lhs;
	return cp /= rhs;
}
template<int mod> ModularArithmetic<mod> operator/ (ll lhs, ModularArithmetic<mod> rhs) {
	return ModularArithmetic<mod>::valueOf(lhs) / rhs;
}

template<int mod> std::ostream &operator<< (std::ostream &stream, ModularArithmetic<mod> zn) {
	return stream << zn.value;
}

template<int mod> std::istream &operator>> (std::istream &stream, ModularArithmetic<mod> &zn) {
	ll value;
	stream >> value;
	zn.value = value % mod;
	return stream;
}
//@prevline
//@prevline