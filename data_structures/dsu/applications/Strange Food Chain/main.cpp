#include "../../relative_dsu.h"
#include "../../../../number_theory/modular_arithmetic.h"
#include "../../../../mass_operations/sum_mo.h"

const int N = 50000;
const int M = 100000;

struct Input {
	int n, m;
	int x[M], y[M], z[M];
	
	bool read () {
		if (scanf("%d%d", &n, &m) != 2) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d%d", &z[i], &x[i], &y[i]);
			--x[i];
			--y[i];
			--z[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	
	void write () {
		printf("%d\n", ans);
	}
};


namespace Main {
	
	struct Solution: Data {
		RelativeDSU<SumMO<ModularArithmetic<3> > > dsu;
		
		void solve () {
			dsu.initialize(n);
			ans = 0;
			forn (i, m) {
				if (x[i] >= n || y[i] >= n) {
					++ans;
					continue;
				}
				if (!dsu.unite(x[i], y[i], ModularArithmetic<3>::valueOf(z[i]))) {
					if (dsu.relation(x[i], y[i]) != z[i]) {
						++ans;
					}
				}
			}
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
	
	#ifdef SG
		freopen("a.in", "r", stdin);
//		freopen("a.out", "w", stdout);
	#else
//		freopen("", "r", stdin);
//		freopen("", "w", stdout);
	#endif
		
	int t;
	scanf("%d", &t);
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	
	return 0;
}

