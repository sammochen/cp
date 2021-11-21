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

#define CAN_COMPILE(NAME, EXPR)          \
    template <typename, typename = void> struct NAME : false_type {};         \
    template <typename T>                struct NAME<T, decltype(EXPR, void())> : true_type {}

CAN_COMPILE(is_pair, T::first && T::second);
CAN_COMPILE(is_streamable, cout << declval<T>());

class Repr {
   public:
    string s, open = "[", close = "]", sep = ", ";

    template <typename T>
    Repr(T t) { s = ev1(t); }

   private:
    template <typename T>
    string ev3(T t, true_type) { return open + ev1(t.first) + sep + ev1(t.second) + close; }
    template <typename T>
    string ev3(T t, false_type) { string ans = open; for (auto a : t) { ans += (ans == open ? "" : sep) + ev1(a); } return ans + close; }

    template <typename T>
    string ev2(T t, true_type) { stringstream ss; ss << t; return ss.str(); }
    template <typename T>
    string ev2(T t, false_type) { return ev3(t, is_pair<T>()); }

    template <typename T>
    string ev1(T t) { return ev2(t, is_streamable<T>()); }
};

string repr() { return ""; }
template <typename T, typename... U>
string repr(T t, U... u) { return Repr(t).s + " " + repr(u...); }

#ifdef TEST
#define debug(...) do { cout << repr("[" + string(#__VA_ARGS__) + "]:", __VA_ARGS__) << endl; } while (false)
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
template <typename A, typename B> bool exist(const A& a, const B& b) { return a.find(b) != a.end(); }

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1};
const VLL dj = {1, -1, 0, 0, -1, -1, 1, 1};
const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5, 1000000207};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;

// clang-format on
