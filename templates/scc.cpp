ll cur_time;
VVLL scc;

void dfs(ll at, VVLL & E, VLL & first, VLL & low, stack<ll> & stack, VLL & onstack) {
	first[at] = cur_time;
	low[at] = cur_time;
	stack.push(at);
	onstack[at] = 1;
	cur_time++;

	for (ll to : E[at]) {
		if (first[to] == -1) {
			dfs(to, E, first, low, stack, onstack);
			low[at] = min(low[at], low[to]);
		} else if (onstack[to]) {
			low[at] = min(low[at], first[to]);
		}
	}

	if (first[at] == low[at]) {
		VLL comp;
		ll last;
		do {
			last = stack.top();
			comp.push_back(last);
			onstack[last] = 0;
			stack.pop();
		} while (last != at);

		scc.push_back(comp);
	}
}	

void go(ll n, VVLL & E) {
	cur_time = 1;
	VLL first(n, -1), low(n), onstack(n);
	stack<ll> stack;

	rep(i,0,n) {
		if (first[i] == -1) dfs(i, E, first, low, stack, onstack);
	}
}
