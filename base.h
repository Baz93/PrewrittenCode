#pragma once
//@prevline
#include <bits/stdc++.h>
using namespace std;

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

#ifdef LIB_ASSERT
	#define lib_assert(...) assert(__VA_ARGS__)
#else
	#define lib_assert(...)
#endif

template<typename T> struct PassArgument {
	typedef typename conditional<
		(//@prevline
			is_trivially_copyable<T>::value && //@prevline
			sizeof(T) <= 12//@prevline
		), //@prevline
		T, const T &//@prevline
	>::type Type;//@prevline
};
//@prevline
template<typename T> T common_argument (initializer_list<T> args) {
	return declval<T>();//@prevline
}//@prevline
//@prevline
#define pass(T) typename PassArgument<T>::Type
#define basetype(...) decltype(common_argument({__VA_ARGS__}))

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
#define sqr(x) _sqr<basetype(x)>(x)
#define umx(x,y) _umx<basetype(x), basetype(y)>(x, y)
#define umn(x,y) _umn<basetype(x), basetype(y)>(x, y)
#define max(x,y) _max<basetype(x, y)>(x, y)
#define min(x,y) _min<basetype(x, y)>(x, y)
//@prevline
//@prevline