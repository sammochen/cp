#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

ll m;
VLL dx = {0,0,1,-1};
VLL dy = {1,-1,0,0};

PLL bfs(ll x, ll y, ll tx, ll ty) {
	ll limit = 100;
	
	map<ll,map<ll,map<ll,ll>>> t, cnt;
	queue<VLL> Q;
	t[x][y][4] = 1;
	cnt[x][y][4] = 1;

	Q.push({x,y,4});

	while (Q.size()) {
		VLL at = Q.front();
		Q.pop();

		ll ti = t[at[0]][at[1]][at[2]];

		if (at[0] == tx && at[1] == ty) {
			limit = ti+5;
		}

		if (ti > limit) break;

		REP(i,0,4) {
			ll xx = at[0] + dx[i];
			ll yy = at[1] + dy[i];
			if (((ti+m-1) % m == 0) && (i == at[2])) continue;

			// if this is the first itme seeing it
			if (t[xx][yy][i] == 0) {
				t[xx][yy][i] = ti+1;
				cnt[xx][yy][i] = cnt[at[0]][at[1]][at[2]];
				cnt[xx][yy][i] %= mod;
				Q.push({xx,yy,i});
			// multiple times seeing it
			} else if (t[xx][yy][i] == ti + 1) {
				cnt[xx][yy][i] += cnt[at[0]][at[1]][at[2]];
				cnt[xx][yy][i] %= mod;
			}
		}
	}

	ll besttime = inf;
	ll count = 0;
	REP(j,0,5) {
		if (t[tx][ty][j] == 0) continue;

		if (t[tx][ty][j] < besttime) {
			besttime = t[tx][ty][j];
			count = 0;
		}
		if (t[tx][ty][j] == besttime) {
			count += cnt[tx][ty][j];
			count %= mod;
		}
	}
	return {besttime - 1, count};
}


void solve() {
	ll x1, y1, x2, y2;
	in(m);
	in(x1,y1,x2,y2);

	PLL ans = bfs(x1,y1,x2,y2);
	cout << ans.first << ' ' << ans.second << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}