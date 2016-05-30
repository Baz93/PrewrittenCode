#pragma once
//@prevline
#include "type_traits.h"
//@prevline
template<typename T> inline auto _sqr (pass(T) x) -> decltype(x * x) {
	return x * x;//@prevline
}//@prevline
//@prevline
template<typename T1, typename T2> inline bool _umx (T1& a, pass(T2) b) {
	if (a < b) {//@prevline
		a = b; //@prevline
		return 1;//@prevline
	} //@prevline
	return 0;//@prevline
}//@prevline
//@prevline
template<typename T1, typename T2> inline bool _umn (T1& a, pass(T2) b) {
	if (b < a) {//@prevline
		a = b; //@prevline
		return 1;//@prevline
	} //@prevline
	return 0;//@prevline
}//@prevline
//@prevline
template<typename T> inline T _max (pass(T) a, pass(T) b) {
	if (b < a) {//@prevline
		return a;//@prevline
	} //@prevline
	return b;//@prevline
}//@prevline
//@prevline
template<typename T> inline T _min (pass(T) a, pass(T) b) {
	if (a < b) {//@prevline
		return a;//@prevline
	} //@prevline
	return b;//@prevline
}//@prevline
//@prevline
#define sqr(x) _sqr<decltype((x))>(x)
#define umx(x,y) _umx<basetype(x), basetype(y)>(x, y)
#define umn(x,y) _umn<basetype(x), basetype(y)>(x, y)
#define max(x,y) _max<basetype(x, y)>(x, y)
#define min(x,y) _min<basetype(x, y)>(x, y)
//@prevline
//@prevline