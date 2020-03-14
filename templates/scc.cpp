#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

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

void solve() {
	cur_time = 1;
	ll n, m;
	VVLL E(n);
	VLL first(n, -1), low(n), onstack(n);
	stack<ll> stack;

	REP(i,0,n) {
		if (first[i] == -1) dfs(i, E, first, low, stack, onstack);
	}
	
	
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}