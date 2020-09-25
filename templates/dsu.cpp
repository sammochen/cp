
VLL par; 

ll getp(ll x) {
	if (par[x] == x) return x;
	par[x] = getp(par[x]);
	return par[x];
}

ll same(ll a, ll b) {
	return getp(a) == getp(b);
}

void merge(ll a, ll b) {
	if (same(a,b)) return;
	par[getp(a)] = getp(b);
}

void init(ll n) {
	par.resize(n);
	rep(i,0,n) par[i] = i;
}

