void dfs(ll at, ll prev, VVLL & E, VLL & tin, VLL & low, VLL & ans, ll & t, ll & root) {
	tin[at] = t;
	low[at] = t;
	t++;

	ll k = 0;
	fe(to, E[at]) {
		if (tin[to] == -1) {
			k++;
			dfs(to, at, E, tin, low, ans, t, root);
			upmin(low[at], low[to]);

			if (at != root && low[to] >= tin[at]) {
				ans[at] = 1;
			} else if (at == root && k > 1) {
				ans[at] = 1;
			}
		} else if (to != prev) {
			upmin(low[at], tin[to]);
		}
	}
}

VLL ap(VVLL & E) {
	ll n = E.size();
	ll t = 1;
	VLL tin(n, -1), low(n, -1), ans(n);

	rep(i,0,n) {
		if (tin[i] == -1) {
			dfs(i, -1, E, tin, low, ans, t, i);
		}
	}
	
	return ans;
}