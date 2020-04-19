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


ll sum(ll x1, ll y1, ll x2, ll y2, VVLL & pre) {
	return pre[x2+1][y2+1] - pre[x1][y2+1] - pre[x2+1][y1] + pre[x1][y1];
}
void solve() {
	ll n, m;
	cin >> n >> m;
	vector<string> A(n);
	REP(i,0,n) cin >> A[i];

	if (n == 1 && m == 1) {
		cout << 1 << endl;
		return;
	}
	if (A[n-1][m-1] == 'R') {
		cout << 0 << endl;
		return;
	}

	VVLL pre(n+1, VLL(m+1));
	REP(i,0,n) {
		REP(j,0,m) {
			pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + (A[i][j] == 'R');
		}
	}

	VVLL D(n+1, VLL(m+1)); // number of ways to reach pos with the last move being D
	VVLL R(n+1, VLL(m+1)); // number of ways to reach pos with the last move being R
	D[n][m-1] = 1;
	R[n-1][m] = 1;

	RREP(i,n-1,0) {
		RREP(j,m-1,0) {
			ll below = sum(i,j,n-1,j,pre);
			ll right = sum(i,j,i,m-1,pre);
			
			R[i][j] = R[i][j+1] + D[i][j+1];
			if (i == n-1) {
				R[i][j] = right ? 0 : 1;
			} else if (A[i][j] == 'R') {
				R[i][j] -= D[i][m-right];
			} 

			D[i][j] = D[i+1][j] + R[i+1][j];
			if (j == m-1) {
				D[i][j] = below ? 0 : 1;
			} else if (A[i][j] == 'R') {
				D[i][j] -= R[n-below][j];
			}

		}
	}

	for (string s : A) debug(s);

	for (auto r : R) debug(r);
	debug("");
	for (auto d : D) debug(d);

	

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}