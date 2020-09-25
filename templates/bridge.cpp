
ll time;

void dfs(ll at, ll prev, VVLL & E, VLL & first, VLL & low, set<PLL> & bridge) {
	first[at] = time;
	low[at] = time;
	time++;
	for (ll to : E[at]) {
		if (to == prev) continue;
		
		if (first[to] == -1) {
			dfs(to, at, E, first, low, bridge);
			low[at] = min(low[at], low[to]);
			if (low[to] > first[at]) {
				bridge.insert({min(at,to), max(at,to)});
			}
		} else {
			low[at] = min(low[at], first[to]);
		}
	}
}	
