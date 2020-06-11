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

ll buf = 15;
ll dp1[100][100][200][5];
ll dp2[100][100][200][5];

void dfs(ll x, ll y, ll t, ll last) {
	if (t >= 200) return;
	if (x+buf < 0 || x+buf >= 100) return;
	if (y+buf < 0 || y+buf >= 100) return;

	if (dp1[x+buf][y+buf][t][last]) return;
	dp1[x+buf][y+buf][t][last] = 1;

	REP(i,0,4) {
		if ((i == last) && (t % m == 0)) continue; 
		dfs(x+dx[i], y+dy[i], t+1, i);
	}
}

ll get(ll x, ll y, ll t, ll d) {
	if (t == 0) {
		return 1;
	}
	if (dp2[x+buf][y+buf][t][d] != -1) {
		return dp2[x+buf][y+buf][t][d];
	}
	
	ll ans = 0;
	REP(i,0,5) {
		if ((t-1) % m == 0 && i == d) continue;

		ll xx = x - dx[d];
		ll yy = y - dy[d];
		if (xx < 0 || xx >= 200 || yy < 0 || yy >= 200) continue;

		if (dp1[x-dx[d]+buf][y-dy[d]+buf][t-1][i]) {
			ans += get(x-dx[d], y-dy[d], t-1, i);
			ans %= mod;
		}
	}
	dp2[x+buf][y+buf][t][d] = ans;
	return ans;
}

void solve() {
	ll x1, y1, x2, y2;
	in(m);
	in(x1,y1,x2,y2);

	mst(dp1, 0);
	mst(dp2, -1);

	dfs(x1, y1, 0, 4);

	ll ok = 0;
	ll t = -1;
	REP(i,0,200) {
		REP(j,0,5) {
			if (dp1[x2+buf][y2+buf][i][j]) {
				t = i;
				ok = 1;
				break;
			}
		}
		if (ok) break;
	}

	ll ans = 0;
	REP(i,0,5) {
		if (dp1[x2+buf][y2+buf][t][i]) {
			ans += get(x2, y2, t, i);
			ans %= mod;
		}
	}

	std::cout << t << ' ' << ans << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}