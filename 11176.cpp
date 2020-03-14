#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

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
typedef vector<db> VDB;
typedef vector<VDB> VVDB;

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	VVDB sumdp, dp;
	db p;

	db sum(ll n, ll big);

	// returns the probability that in a n size, the max streak is big
	db get(ll n, ll big) {
		if (n < big) return 0;
		if (n == big) return pow(p,n);
		if (big == 0) return pow((1-p),n);
		if (n == -1) return 0;
		if (dp[n][big] >= 0) return dp[n][big];

		// // either have the streak there, or dont
		// double ans = get(n-1, big) - get(big-1,big-1) + get(big, big);
		

		double ans = 0;
		REP(start,1,n-big) {
			// note big - 1
			ans += sum(start-1, big - 1) * get(1,0) * get(big,big) * get(1,0) * sum(n - big - 2 - (start - 1), big);
		}
		ans += get(big,big) * get(1,0) * sum(n-big-1, big - 1); // note big - 1
		ans += get(big,big) * get(1,0) * sum(n-big-1, big);

		dp[n][big] = ans;
		return ans;
	}

	db sum(ll n, ll big) {
		if (big < 0) return 0;
		if (sumdp[n][big] == -1) sumdp[n][big] = get(n, big) + sum(n, big - 1);
		return sumdp[n][big];
	}

	void main() {
		ll n;
		while (cin >> n >> p, n) {
			dp.clear(); sumdp.clear();
			dp.resize(n+1, VDB(n+1, -1)); sumdp.resize(n+1, VDB(n+1, -1));

			db ans = 0;
			REP(i,0,n+1) {
				ans += i * get(n, i);
			}
			
			printf("%.10f\n", ans);
		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
