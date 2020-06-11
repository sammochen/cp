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

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll h = pow(a, b/2);
	ll ans = b % 2 ? h * h % mod * a : h * h;
	ans %= mod;
	return ans;
}

ll inv(ll a) {
	return pow(a,mod-2);
}

void multrow(VVLL & grid, ll row, ll k) {
	REP(j,0,sz(grid[0])) {
		grid[row][j] = grid[row][j] * k % mod;
	}
}

// row1 is og, row2 should go to 0
void makezero(VVLL & grid, ll row1, ll row2, ll k) {
	REP(j,0,sz(grid[0])) {
		grid[row2][j] = grid[row2][j] + grid[row1][j] % mod * k % mod;
		grid[row2][j] %= mod;
	}
}


void solve() {
	ll n;
	in(n);
	VLL A(n);
	in(A);

	VLL go(n+10);
	REP(i,0,sz(go)) {
		go[i] = i >= sz(A) ? sz(A) - 1 : A[i] == 0 ? i : A[i] - 1;
	}

	// i want to work out the expected number of turns to finish from 0

	VVLL grid(n, VLL(n));

	ll sixth = pow(6LL,mod-2);
	REP(i,0,n-1) {
		REP(j,1,7) {
			grid[i][go[i+j]] = grid[i][go[i+j]] + sixth % mod;
		}
	}
	REP(i,0,n) grid[i][i] = grid[i][i] - 1;
	REP(i,0,n) grid[i][n-1] = 1;

	VVLL x(n, VLL(1));
	x[n-1][0] = 1;

	REP(i,0,n) {
		multrow(x, i, inv(grid[i][i]));
		multrow(grid, i, inv(grid[i][i]));
		
		REP(j,0,n) {
			if (i == j) continue;
			makezero(x, i, j, mod-grid[j][i]);
			makezero(grid, i, j, mod-grid[j][i]);
		}
	}

	ll ans = x[0][0];
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}