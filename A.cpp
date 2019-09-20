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

#define V first
#define S second

namespace SOLVE {	
	// PLL: value, suit

	// high 1
	// pair 2
	// 2pair 3
	// triple 4
	// straight 5
	// flush 6
	// fullhouse 7
	// fours 8
	// straightflush 9

	ll high() {
		return 0;
	}
	template <typename A, typename... B> ll high(A a, B... b) {
		return a + 20 * high(b...);
	}

	ll straight(vector<PLL> hand) {
		// remembering 2 3 4 5 14 case
		if (hand[4].V == 14 && hand[3].V == 5) {
			hand[4].V = 1;
			sort(hand.begin(), hand.end());
		}

		REP(i,0,4) {
			if (hand[i].V + 1 != hand[i+1].V) return 0;
		}

		return hand[4].V;
	}

	ll flush(vector<PLL> hand) {
		REP(i,0,4) {
			if (hand[i].S != hand[4].S) return 0;
		}
		return 1;
	}

	VVLL freq(vector<PLL> hand) {
		VLL f(13);
		for (PLL card : hand) {
			f[card.V]++;
		}
		VVLL ff(5); // ff[2] gives the numbers that come up twice

		REP(i,0,13) {
			ff[f[i]].push_back(i);
		}


		return ff;
	}

	PLL score(vector<PLL> hand) {
		
		VVLL ff = freq(hand);
		ll str = straight(hand);
		ll fl = flush(hand);

		if (str && fl) return MP(9,str);
		if (ff[4].size()) return MP(8, ff[4][0]);
		if (ff[3].size() && ff[2].size()) return MP(7, ff[3][0]);
		if (fl) return MP(6,high(hand[0].V, hand[1].V, hand[2].V, hand[3].V, hand[4].V));
		if (str) return MP(5,str);
		if (ff[3].size()) return MP(4, high(ff[1][0], ff[1][1], ff[3][0]));
		if (ff[2].size() == 2) return MP(3, high(ff[1][0], ff[2][0], ff[2][1]));
		if (ff[2].size() == 1) return MP(2, high(ff[1][0], ff[1][1], ff[1][2], ff[2][0]));
		return MP(1, high(ff[1][0], ff[1][1], ff[1][2], ff[1][3], ff[1][4]));
	}

	ll winner(vector<PLL> hand1, vector<PLL> hand2) {
		PLL score1 = score(hand1);
		PLL score2 = score(hand2);
		if (score1.first > score2.first) {
			return 0;
		} else if (score1.first < score2.first) {
			return 1;
		} else {
			return score2.second > score1.second;
		}
	}

	void main() {
		vector<PLL> hand;

		ll a, b;
		REP(i,0,5) {
			cin >> a >> b;
			hand.push_back(MP(a,b));
		}

		PLL ans = combos(hand);
		debug(ans.first, ans.second);
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
