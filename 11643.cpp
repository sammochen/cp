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
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

VLL bfs(ll s, ll & n) {
	VLL di = {1,2,2,1,-1,-2,-2,-1};
	VLL dj = {2,1,-1,-2,-2,-1,1,2};
	VLL dist(n*n, inf);
	queue<ll> Q;
	Q.push(s);
	dist[s] = 0;
	while (Q.size()) {
		ll at = Q.front();
		ll x = at/n;
		ll y = at%n;
		Q.pop();

		REP(i,0,8) {
			ll xx = x + di[i];
			ll yy = y + dj[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			ll to = xx*n+yy;
			if (dist[to] == inf) {
				dist[to] = dist[at] + 1;
				Q.push(to);
			}
		}
	}
	return dist;
}

struct todo {
	ll a, b, mask, dist;
};

bool operator<(const todo & a, const todo & b) {
	return a.dist > b.dist;
}

ll test = 1;
void solve() {
	ll n, k;
	cin >> n >> k;
	VLL A(k);
	REP(i,0,k) {
		ll x, y;
		cin >> x >> y;
		x--; y--;
		A[i] = x*n + y;
	}

	VVLL moves(k, VLL(k));
	REP(i,0,k) {
		VLL d = bfs(A[i], n);
		REP(j,0,k) {
			moves[i][j] = d[A[j]];
		}
	}

	// do a multi-sourced dijkstras
	priority_queue<todo> Q;
	VVVLL dist(k, VVLL(k, VLL((1LL << k), inf)));
	REP(i,0,k) {
		todo state = {i,i,(1LL<<i),0};
		Q.push(state);
		dist[i][i][1LL<<i] = 0;
	}

	while (Q.size()) {
		todo at = Q.top(); Q.pop();

		// go to the next one
		REP(i,0,k) {
			ll cost = moves[at.b][i];
			if (dist[at.a][i][at.mask | (1LL << i)] <= dist[at.a][at.b][at.mask] + cost) continue;

			todo to = {at.a, i, at.mask | (1LL << i), dist[at.a][at.b][at.mask] + cost};
			Q.push(to);
			dist[at.a][i][at.mask | (1LL << i)] = dist[at.a][at.b][at.mask] + cost;
		}
	}

	ll ans = inf;
	REP(i,0,k) {
		ans = min(ans, dist[i][i][(1LL << k) - 1]);
	}

	printf("Case %lld: %lld\n", test++, ans);
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}