#include "data_structures/varray.h"
#ifdef DSU_RETRIEVE
#include "data_structures/retriever.h"
#endif
//@prevline
template<
	
	#ifdef DSU_INFO
	typename Info, //@prevline
	#endif
	#ifdef DSU_RELATION
	typename Relation, //@prevline
	#endif
	int N = -1//@prevline
	#ifdef DSU_RETRIEVE
	, int M = -1//@prevline
	#endif
> class DSU_CLASSNAME {
private:
	struct Item {
		int parent, size;
		#ifdef DSU_INFO
		typename Info::Value info;
		#endif
		#ifdef DSU_RELATION
		typename Relation::Value relation;
		#endif
	};
	
	#ifdef DSU_INFO
	Info imo;
	#endif
	#ifdef DSU_RELATION
	Relation rmo;
	#endif
	Varray<Item, N> a;
	
	#ifdef DSU_RETRIEVE
	Retriever<Item> r;
	
	#endif
	void link (int u, int v
		#ifdef DSU_RELATION
		, pass(typename Relation::Value) rel//@prevline
		#endif
	) {//@prevline
		#ifdef DSU_RETRIEVE
		r.push(a[u]);
		r.push(a[v]);
		#endif
		a[u].parent = v;
		a[v].size += a[u].size;
		#ifdef DSU_INFO
		imo.set_unite_l(a[v].info, a[u].info);
		#endif
		#ifdef DSU_RELATION
		a[u].relation = rel;
		#endif
	}
	
public:
	DSU_CLASSNAME () {}
	
	void initialize (
		int size
		#ifdef DSU_INFO
		, pass(Info) info_mo = Info()//@prevline
		#endif
		#ifdef DSU_RELATION
		, pass(Relation) relation_mo = Relation()//@prevline
		#endif
	) {
		#ifdef DSU_INFO
		imo = info_mo;
		#endif
		#ifdef DSU_RELATION
		rmo = relation_mo;
		#endif
		a.resize(size);
		forn (i, sz(a)) {
			a[i].parent = i;
			a[i].size = 1;
			#ifdef DSU_INFO
			a[i].info = imo.neutral();
			#endif
			#ifdef DSU_RELATION
			a[i].relation = rmo.neutral();
			#endif
		}
	}
	
	int get_size (int v) const {
		return a[get_root(v)].size;
	}
	
	int get_root (int v) {
		if (a[v].parent == v) {
			return v;
		}
		int result = get_root(a[v].parent);
		#ifdef DSU_RETRIEVE
		r.push(a[v]);
		#endif
		#ifdef DSU_RELATION
		rmo.set_unite_r(a[v].relation, a[a[v].parent].relation);
		#endif
		return a[v].parent = result;
	}
	
	bool connected (int u, int v) {
		return get_root(u) == get_root(v);
	}
	
	#ifdef DSU_INFO
	Info &get_info (int v) {
		return a[get_root(v)].info;
	}
	
	const Info &get_info (int v) const {
		return a[get_root(v)].info;
	}
	
	#endif
	#ifdef DSU_RELATION
	typename Relation::Value relation (int u) {
		get_root(u);
		return a[u].relation;
	}
	
	typename Relation::Value relation (int u, int v) {
		return rmo.unite(relation(u), rmo.reverse(relation(v)));
	}
	
	#endif
	bool unite (int u, int v
		#ifdef DSU_RELATION
		, pass(typename Relation::Value) rel//@prevline
		#endif
	) {//@prevline
		#ifdef DSU_RELATION
		rmo.set_unite_l(rel, rmo.reverse(relation(u)));
		#endif
		u = get_root(u);
		#ifdef DSU_RELATION
		rmo.set_unite_r(rel, relation(v));
		#endif
		v = get_root(v);
		if (u == v) {
			return 0;
		}
		if (a[u].size > a[v].size) {
			swap(u, v);
			#ifdef DSU_RELATION
			rel = rmo.reverse(rel);
			#endif
		}
		link(u, v
			#ifdef DSU_RELATION
			, rel//@prevline
			#endif
		);//@prevline
		return 1;
	}
	#ifdef DSU_RETRIEVE
	
	int get_state () const {
		return r.get_state();
	}
	
	void retrieve (int state) {
		r.retrieve(state);
	}
	#endif
};
//@prevline
//@prevline