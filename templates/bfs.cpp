VLL bfs(VVLL & E, ll s) {
	VLL d(E.size(), inf);
	queue<ll> Q;
	Q.push(s);
	d[s] = 0;
	while (Q.size()) {
		ll at = Q.front();
		Q.pop();

		for (ll to : E[at]) {
			if (d[to] == inf) {
				d[to] = d[at] + 1;
				Q.push(to);
			}
		}
	}
	return d;
}

void solve() {
	
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}