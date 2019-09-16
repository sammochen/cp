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

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
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

namespace SOLVE {
	ll nax = 400;
	
	VLL fill(string s) {
		VLL A(nax);
		s = string(nax - s.size(), '0') + s;
		
		REP(i,0,nax) {
			A[i] = s[i] - '0';
		}
		return A;
	}
	
	VLL add(VLL a, VLL b) {
		VLL c(nax);
		ll carry = 0;
		
		RREP(i,nax-1,0) {
			ll x = a[i] + b[i] + carry;
			carry = 0;
			
			if (x >= 10) {
				carry = 1;
				x -= 10;
			}
			
			c[i] = x;
		}
		if (carry) cout << "overflow!" << endl;
		return c;
	}
	
	VLL times(VLL a, ll k) {
		VLL c(nax);
		REP(i,0,k) {
			c = add(a, c);
		}
		return c;
	}
	
	VLL power(ll a, ll k) {
		VLL c(nax);
		c[nax-1] = 1;
		REP(i,0,k) {
			c = times(c, a);
		}
		return c;
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
