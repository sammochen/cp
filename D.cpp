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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

void myset(ll & a, ll ind, ll value) {
	a &= ~(7LL << (ind*3));
	a |= (value << (ind*3));
}

ll myget(ll a, ll ind) {
	a = a >> (3*ind);
	return a&7;
}

void rotate(ll & state, ll ind) {
	myset(state, ind, (myget(state, ind) + 1) % 6);
}

ll change(ll state, ll ind) {
	ll at = myget(state,ind);
	if (at == 0) {
		if (ind != 0) rotate(state, ind-1);
		if (ind != 7) rotate(state, ind+1);
		return state;
	} else if (at == 1) {
		if (ind == 0 || ind == 7) return state;
		myset(state, ind+1, myget(state, ind-1));
		return state;
	} else if (at == 2) {
		rotate(state, 7-ind);
		return state;
	} else if (at == 3) {
		if (ind <= 3) {
			REP(i,0,ind) rotate(state, i);
		} else {
			REP(i,ind+1,8) rotate(state, i);
		}
		return state;
	} else if (at == 4) {
		if (ind == 0 || ind == 7) return state;
		if (ind <= 3) {
			rotate(state, 0);
			rotate(state, 2*ind);
		} else {
			rotate(state, 7);
			rotate(state, 2*ind-7);
		}
		return state;
	} else {
		ll x = ind+1;
		ll y = x%2 ? (x+9)/2 : x/2;
		rotate(state, y-1);
		return state;
	}
}
VLL dist(17000000);

ll bfs(ll s, ll t) {
	if (s == t) return 0;
	
	dist[s] = 1;
	queue<ll> Q;
	Q.push(s);
	while (Q.size()) {
		ll at = Q.front(); Q.pop();

		REP(i,0,8) {
			ll to = change(at, i);
		
			if (dist[to] == 0) {
				dist[to] = dist[at] + 1;
				Q.push(to);
				if (to == t) return dist[to] - 1;
			}
		}
	}
	return -1;
}

void solve() {
	string s, t;
	cin >> s >> t;
	ll A = 0, B = 0;
	REP(i,0,8) myset(A,i,s[i]-'A');
	REP(i,0,8) myset(B,i,t[i]-'A');

	cout << bfs(A,B) << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}