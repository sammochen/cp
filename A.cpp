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

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;

namespace SOLVE {
	void main() {
		VLL four(4);
		
		four[0] = 4;
		four[1] = 9;
		four[2] = 6;
		four[3] = 15;
		
		ll q;
		cin >> q;
		REP(i,0,q) {
			ll x;
			cin >> x;
			if (x >= four[x%4]) {
				cout << (x - four[x%4]) / 4 + 1 << endl;
			} else {
				cout << -1 << endl;
			}
		}
			
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
