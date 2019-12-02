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

namespace SOLVE {
	class big {
		public:

		big() {

		}
		
		big(ll x) {
			*this = x;
		}

		big(VLL x) {
			*this = x;
		}

		big& operator=(const ll & x) {
			A = {abs(x)};
			sign = x == 0 ? 0 : x > 0 ? 1 : -1;
			make_proper();
			return *this;
		}

		big& operator=(const VLL &B) {
			A = B;
			sign = 1;
			make_proper();
			return *this;
		}

		big& operator=(const big &b) {
			A = b.A;
			sign = b.sign;
			make_proper();
			return *this;
		}


		big operator+(const big & other) {
			ll n = max(A.size(), other.A.size());
			VLL ans(n);
			REP(i,0,n) {
				if (i < A.size()) ans[i] += A[i];
				if (i < other.A.size()) ans[i] += other.A[i];
			}
			big res;
			res = ans;
			return res;
		}

		big operator==(ll & other) {
			big o = other;
			return *this == o;
		}

		big operator==(big & other) {
			return to_ll() == other.to_ll() && sign == other.sign;
		}

		big operator*(const big & other) {
			if 
		}
		
		big operator/(const big & other) {
			return division(other).first;
		}

		big operator%(const big & other) {
			return division(other).second;
		}

		ll to_ll() {
			return stoll(to_string());
		}

		ll size() {
			return A.size();
		}


		string to_string() {
			string s;
			RREP(i,A.size()-1,0) s.push_back(A[i] + '0');
			return s;
		}

		private:
		VLL A;
		int sign = 1;
		int base = 10; 
		
		void make_proper() {
			REP(i,0,A.size()) {
				if (A[i] >= base) {
					if (i == A.size() - 1) {
						A.push_back(0);
					} 
					A[i+1] += A[i] / base;
					A[i] %= base;
				}
			}

			ll index = 0;
			REP(i,0,A.size()) {
				if (A[i] != 0) index = i;
			}
			A.resize(index+1);
		}

		pair<big,big> division(big b) {
			ll divisor = b.to_ll();
			big copy = (*this).A;
			big mod;

			RREP(i,copy.size()-1,0) {
				if (i != 0) copy.A[i-1] += (copy.A[i] % divisor) * base;
				else mod = copy.A[i] % base;
				copy.A[i] = copy.A[i] / divisor;
			}

			copy.make_proper();
			mod.make_proper();
			return {copy, mod};		
		}
	};

	std::ostream & operator<<(ostream &os, big obj) {
		os << obj.to_string();
		return os;
	}
	 
	void main() {
		print(3 == 2);
		
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
