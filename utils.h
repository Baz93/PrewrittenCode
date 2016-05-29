#pragma once
//@prevline
#include "template.h"
#include "pass_argument.h"
//@prevline
template<typename T> inline auto sqr (pass(T) x) -> decltype(x * x) {
	return x * x;//@prevline
}//@prevline
//@prevline
template<typename T1, typename T2> inline bool umx (T1& a, pass(T2) b) {
	if (a < b) {//@prevline
		a = b; //@prevline
		return 1;//@prevline
	} //@prevline
	return 0;//@prevline
}//@prevline
//@prevline
template<typename T1, typename T2> inline bool umn (T1& a, pass(T2) b) {
	if (b < a) {//@prevline
		a = b; //@prevline
		return 1;//@prevline
	} //@prevline
	return 0;//@prevline
}//@prevline
//@prevline
template<typename T> inline T _min (pass(T) a, pass(T) b) {
	if (a < b) {//@prevline
		return a;//@prevline
	} //@prevline
	return b;//@prevline
}//@prevline
//@prevline
template<typename T> inline T _max (pass(T) a, pass(T) b) {
	if (b < a) {//@prevline
		return a;//@prevline
	} //@prevline
	return b;//@prevline
}//@prevline
//@prevline
#define min _min
#define max _max
//@prevline
//@prevline