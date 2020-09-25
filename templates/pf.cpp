
ll nax = 1005;
VLL p(nax*nax, 1);
VLL P;

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

map<ll,ll> pf(ll x) {
    map<ll,ll> f;
    rep(i,0,sz(P)) {
        if (P[i] * P[i] > x) break;
        while (x % P[i] == 0) {
            f[P[i]]++;
            x /= P[i];
        }
    }
    if (x > 1) f[x]++;
    return f;
}
