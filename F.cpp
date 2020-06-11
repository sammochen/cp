#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define FE(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pqueue priority_queue

struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	string f(db x) { return to_string(x); }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

db dist(vector<db> a, vector<db> b) {
	return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}
void solve() {
	ll n;
	cin >> n;
	vector<vector<db>> A(n, vector<db>(3));
	ll allzero = 1;
	REP(i,0,n) {
		REP(j,0,3) {
			cin >> A[i][j];
		}
	}

	vector<db> x, y;

	// for every pair of numbers
	REP(i,0,n) {
		REP(j,i+1,n) {
			// work out the meeting point(s)
			db r0 = A[i][2];
			db r1 = A[j][2];
			db d = dist(A[i], A[j]);

			db a = (r0*r0 - r1*r1 + d*d) / (2*d);
			db h = sqrt(r0*r0 - a*a);

			db x2 = A[i][0] + a*(A[j][0] - A[i][0]) / d;
			db y2 = A[i][1] + a*(A[j][1] - A[i][1]) / d;

			for (ll k = -1; k <= 1; k += 2) {
				db xx = x2 + k * h*(A[j][1] - A[i][1]) / d;
				db yy = y2 - k * h*(A[j][0] - A[i][0]) / d;

				x.pb(xx);
				y.pb(yy);
			} 
		}

		db dd = dist(A[i], {0,0});
		if (A[i][0] == 0 && A[i][1] == 0) {
			x.pb(0);
			y.pb(A[i][2]);
		} else {
			db xx = A[i][0] * (1 + A[i][2] / dd);
			db yy = A[i][1] * (1 + A[i][2] / dd);
			
			x.pb(xx);
			y.pb(yy);
		}
	}

	db ans = 0;
	REP(i,0,sz(x)) {
		ll ok = 1;
		FE(c,A) {
			if (dist({x[i], y[i]}, c) > c[2] + 1e-9) {
				ok = 0;
				break;
			}
		}
		if (ok) ans = max(ans, dist({0,0}, {x[i], y[i]}));
	}

	printf("%.3f\n", ans);
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}