#include "base.h"
//@prevline
constexpr int sufficient_pow (int n) {
	n <= 0 ? n : sufficient_pow((n + 1) / 2) * 2;
}
//@prevline
//@prevline