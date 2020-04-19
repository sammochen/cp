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

struct point {
	ll x, y;
};

// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
ll cw(point a, point b, point c) {
	ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	return v == 0 ? 0 : v < 0 ? -1 : 1;
}

bool operator<(const point & a, const point & b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

vector<point> hull(vector<point> & A) {
	ll n = A.size();
	sort(A.begin(), A.end());
	vector<point> H(2*n);

	ll k = 0; // size
	REP(i,0,n) {
		while (k >= 2 && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	ll t = k+1;
	RREP(i,n-2,0) { // takes it all the way to the end
		while (k >= t && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	H.resize(k-1); // discards the last one
	return H;
}
void solve() {

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}