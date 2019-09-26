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
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

const ll inf = 1e9 + 7;

namespace SOLVE {	
	// just bigger
	ll bs(VLL &A, ll k) {
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L+R)/2;
			if (A[M] > k) R = M;
			else L = M+1;
		}
		return L;
	}
			
			
	void main() {
		
		
		ll n, x;
		cin >> n;
		
		VLL endno(n+1, inf);
		endno[0] = -1;
		ll ans = 0;
		
		REP(i,0,n) {
			cin >> x;
			
			if (x <= endno[1]) {
				endno[1] = x;
			} else {
	
				// find element that is just smaller
				ll j = bs(endno, x);
				endno[j] = x;
				ans = max(ans, j);
			}
		}
		
		cout << ans << endl;
		
		
			
			
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
