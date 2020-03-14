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

ll bfs(VVLL s) {
	map<VVLL,ll> d;
	queue<VVLL> Q;
	Q.push(s);
	d[s] = 1;
	while (Q.size()) {
		VVLL at = Q.front();
		Q.pop();

		if (d[at] == 51) break;

		ll good = 1;
		ll freei = -1, freej = -1;
		REP(i,0,4) {
			REP(j,0,4) {
				if (at[i][j] == 0) {
					freei = i;
					freej = j;
				}
				if (at[i][j] != (i*4+j+1)%16) good = 0;
			}
		}
		if (good) return d[at];

		VLL di = {0,0,1,-1};
		VLL dj = {1,-1,0,0};
		REP(x,0,4) {
			ll ii = freei + di[x];
			ll jj = freej + dj[x];
			if (ii < 0 || ii >= 4 || jj < 0 || jj >= 4) continue;
			VVLL to = at;
			to[freei][freej] = at[ii][jj];
			to[ii][jj] = 0;
			if (d[to] == 0) {
				d[to] = d[at] + 1;
				Q.push(to);
			}
		}
	}
	return -1;
}

void solve() {
	VVLL A(4, VLL(4));
	REP(i,0,4) REP(j,0,4) {
		cin >> A[i][j];
	}

	ll ans = bfs(A);
	debug(ans);
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}