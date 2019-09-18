/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

string to_string() {return "";}
string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
template <typename A> string to_string(A v) { string s = "("; int first = 1; for (auto a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename Head, typename... Tail> string to_string(Head H, Tail... T) { to_string(H) + " " + to_string(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]: " + to_string(__VA_ARGS__) << endl; } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;

namespace SOLVE {
	ll mod = 1e9 + 7;
	
	VVLL operator*(VVLL a, VVLL b) {
		VVLL c(a.size(), VLL(b[0].size()));
		
		REP(i,0,a.size()) {
			REP(j,0,a[0].size()) {
				REP(k,0,b[0].size()) {
					c[i][k] += a[i][j] * b[j][k];
					c[i][k] %= mod;
				}
			}
		}
		
		return c;			
	}
	
	VVLL operator^(VVLL a, ll k) {
		if (k == 1) {
			return a;
		}
		VVLL half = a ^ (k / 2);
		half = half * half;
		if (k % 2) {
			half = half * a;
		}
		return half;
	}

	void main() {
		
		
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
