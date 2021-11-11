// clang-format off

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll, ll> PLL;
typedef map<ll, ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

#define rep(x, l, u) for (ll x = l; x < u; x++)
#define rrep(x, l, u) for (ll x = l; x >= u; x--)
#define fe(x, a) for (auto x : a)
#define fce(x, a) for (const auto& x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x, v) memset(x, v, sizeof(x))
#define sz(x) (ll) x.size()
#define lg(x) (ll) x.length()

#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset

namespace Debug {
const string open = "[", close = "]", sep = ", ";
ll n = 5;

string f() { return "\n"; }
string f(string s) { return s; }
string f(char c) { return string(1, c); }
string f(const char* a) { return a; }

string f(int x) { return to_string(x); }
string f(float x) { return to_string(x); }
string f(ll x) { return to_string(x); }
string f(db x) { return to_string(x); }

template<typename I> string fit(I b, I e) { string s = open + f(*(b++)); while (b != e) { s += sep + f(*(b++)); } s += close; return s; }
template<typename A, typename B> string f(pair<A, B> p) { return open + f(p.first) + sep + f(p.second) + close; }

template<typename A> string f(A a[]) { return fit(a, a + n); }
template<typename A> string f(A a) { return fit(a.begin(), a.end()); }

template<typename H, typename... T> string f(H h, T... t) { return f(h) + " " + f(t...); }
};  // namespace Debug

#ifdef SAM
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]: ", cerr << Debug::f(__VA_ARGS__) << endl; } while (false)
#else
#define debug(...) do {} while (false)
#endif

ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return ( 1LL << x ); }
ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }
ll isvowel(char c) { return string("aeiou").find(c) < 5; }

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss(s); while (ss >> s) ans.pb(s); return ans; }
template<typename A> A reversed(const A & a) { A b = a; reverse(all(b)); return b; }

void makemod(ll & x, ll m) { x %= m; if (x < 0) { x += m; } }
ll getmod(ll x, ll m) { makemod(x, m); return x; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1};
const VLL dj = {1, -1, 0, 0, -1, -1, 1, 1};
const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5, 1000000207};
const ll mod = mods[0];
const ll inf = mods[3];
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
    rep(i, 0, t) solve();
    return 0;
}