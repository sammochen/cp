VVLL operator*(VVLL a, VVLL b) {
	VVLL c(sz(a), VLL(sz(b)));
	
	rep(i,0,sz(a)) {
		rep(j,0,sz(a[0])) {
			rep(k,0,sz(b[0])) {
				c[i][k] += a[i][j] * b[j][k];
				c[i][k] %= mod;
			}
		}
	}
	
	return c;			
}

VVLL operator^(VVLL a, ll k) {
	if (k == 0) {
		VVLL b(sz(a), VLL(sz(a)));
		rep(i,0,sz(a)) b[i][i] = 1;
		return b;
	}
	VVLL half = a ^ (k / 2);
	half = half * half;
	if (k % 2) {
		half = half * a;
	}
	return half;
}

