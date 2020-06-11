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

ll both(VLL & A, ll p) {
	ll i = 1, j = sz(A)-2;
	REP(k,0,p) {
		i++;
		j--;
	}

	if (i >= j) return 0;
	ll total = 0;
	REP(k,i,j+1) {
		total += A[k];
	}
	return total;
}

ll get(VLL & A, ll p) {
	ll n = A.size();

	VLL pre(n+1);
	ll total = 0;
	REP(i,0,n) {
		total += A[i];
		pre[i+1] = pre[i] + A[i];
	}

	if (sz(pre) <= p) return 0;
	ll best = 0;
	REP(i,0,p+1) {
		ll cur = pre[min(n,2*i+1)];
		ll other = pre[n] - pre[max(0LL,n-2*(p-i)-1)];
		
		best = max(best, cur+other);
	}

	return max(0LL, total - best);
}

void solve() {
	ll n, p;
	string s;
	in(n,p,s);

	VLL seg;
	ll cur = 1;
	REP(i,1,n) {
		if (s[i] != s[i-1]) {
			seg.push_back(cur);
			cur = 1;
		} else {
			cur++;
		}
	}
	seg.push_back(cur);
	ll m = sz(seg);
	ll ans = get(seg, p);
	if (m % 2) {
		ans = min(ans, both(seg, p));
	} else if (p > 0) {
		VLL seg1, seg2;
		REP(i,1,m) seg1.push_back(seg[i]);
		seg1[0] += seg[0];

		REP(i,0,m-1) seg2.push_back(seg[i]);
		seg2[m-2] += seg[m-1];

		ans = min({ans, both(seg1, p-1), both(seg2, p-1)});
	} 

	cout << ans << endl;

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}