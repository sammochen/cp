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

ll test = 1;
void solve() {
	ll n;
	cin >> n;
	vector<PLL> A(n);
	REP(i,0,n) cin >> A[i].fi >> A[i].se;

	if (n == 1) {
		printf("Case #%lld: 1\n", test++);
		return;
	}

	// for each gradient, count how many it has
	// also for each graidnet, keep track of how many are on that one line


	// cnt[gradpair][c]
	map<PLL,map<ll,set<PLL>>> cnt;

	REP(i,0,n) {
		REP(j,i+1,n) {
			// try i->j
			ll dx = A[j].fi - A[i].fi;
			ll dy = A[j].se - A[i].se;			

			

			ll g = __gcd(dx, dy);
			dx /= g;
			dy /= g;
			if (dy < 0) {
				dx *= -1;
				dy *= -1;
			}

			ll c = A[i].fi * dy - A[i].se * dx;

			cnt[{dx,dy}][c].insert(A[i]);
			cnt[{dx,dy}][c].insert(A[j]);
		}
	}

	ll ans = 0;
	FE(grad,cnt) {
		ll total = 0;
		FE(x, grad.second) {
			ll y = x.second.size();
			total += y;
		}
		total -= total % 2;
		upmax(ans, total);
	}
	
	printf("Case #%lld: %lld\n", test++, min(n, ans+2));
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}