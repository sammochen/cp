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

struct hasher {
	string s;
	ll mod = 1000000207;
	ll seed = 31;
	VLL pow, val;

	ll toll(char c) {
		return c - 'a' + 1;
	}
	hasher(string str) : s(str) {
		pow.resize(s.length() + 1);
		val.resize(s.length() + 1);
		pow[0] = 1;
		REP(i,0,s.length()) {
			val[i+1] = (val[i] + toll(s[i]) * pow[i] % mod) % mod;
			pow[i+1] = (pow[i] * seed) % mod;
		}
	}

	ll f(ll i, ll j) {
		ll diff = (val[j+1] - val[i] + mod) % mod;
		// times this by how far away i is! 
		diff *= pow[s.length() - i];
		diff %= mod;
		return diff;
	}
};

void solve() {

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}