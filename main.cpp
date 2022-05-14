#include <bits/stdc++.h>

using namespace std;

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
// --------------------------------- DEBUG ---------------------------------
namespace Debug {
const string open = "[", sep = ", ", close = "]";
struct Second {}; struct First : Second {};

template <typename T>
auto one(T t, First) -> decltype(cerr << t, string()) { stringstream ss; ss << t; return ss.str(); }
template <typename T>
auto one(T t, Second) -> decltype(t.first, t.second, string()) { return open + one(t.first, First()) + ", " + one(t.second, First()) + close; }
template <typename T>
auto one(T t, Second) -> decltype(t.begin(), t.end(), string() ) { string ans = open; for (auto a : t) { ans += (ans == open ? "" : sep) + one(a, First()); } return ans + close; }

string mult() { return ""; }
template <typename A, typename... B>
string mult(A a, B... b) { return one(a, First()) + " " + mult(b...); }
}  // namespace Debug
#ifdef DEBUG
#define debug(...) do { cerr << Debug::mult("[" + string(#__VA_ARGS__) + "]:", __VA_ARGS__) << endl; } while (false)
#else
#define debug(...) do {} while (false)
#endif
// --------------------------------- DEBUG ---------------------------------

ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return ( 1LL << x ); }
ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }
VS ssplit(string s) { VS ans; SS ss(s); while (ss >> s) { ans.push_back(s); } return ans; }

void makemod(ll& x, ll m) { x %= m; if (x < 0) { x += m; } }
ll getmod(ll x, ll m) { makemod(x, m); return x; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }

template<typename A, typename B> void upmin(A& x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A& x, B v) { x = max(x, (A)v); }
template<typename A> A reversed(const A& a) { A b = a; reverse(all(b)); return b; }

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1};
const VLL dj = {1, -1, 0, 0, -1, -1, 1, 1};
const ll mod = 1'000'000'007, mod2 = 998'244'353, mod3 = 1'000'000'207, mod4 = 1'000'003;
const ll inf = (ll)1e18 + 5;
const db eps = 1e-10;
const db pi = acos(0) * 2;

// clang-format on

void solve() {
    //
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
#ifdef DEBUG
    t = 2;
#endif
    rep(i, 0, t) solve();
    return 0;
}
