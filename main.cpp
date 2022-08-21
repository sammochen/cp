#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 1
#endif

using ll = long long;
using db = long double;
using VS = vector<string>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using PLL = pair<ll, ll>;
using MLL = map<ll, ll>;
using SLL = set<ll>;
using QLL = queue<ll>;
using SS = stringstream;

#define rep(x, l, u) for (ll x = l; x < u; x++)
#define rrep(x, l, u) for (ll x = l; x >= u; x--)
#define fe(x, a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x, v) memset(x, v, sizeof(x))
#define sz(x) (ll) x.size()

#define umap unordered_map
#define uset unordered_set
#define mset multiset

// clang-format off

ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return ( 1LL << x ); }
ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }
void makemod(ll& x, ll m) { x %= m; if (x < 0) { x += m; } }
ll getmod(ll x, ll m) { makemod(x, m); return x; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }

template <typename A, typename B> bool upmin(A& x, B v) { if (v >= x) return false; return x = v, true; }
template <typename A, typename B> bool upmax(A& x, B v) { if (v <= x) return false; return x = v, true; }

// clang-format on

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1}, dj = {1, -1, 0, 0, -1, -1, 1, 1};
const ll mod = 1'000'000'007, mod2 = 998'244'353, inf = (ll)1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    //
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll t = 1;
    cin >> t;
    rep(i, 0, t) solve();
    return 0;
}
