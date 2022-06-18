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
void addmod(ll &a, ll b, ll m) { a += b; if (a >= m) a -= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }

template<typename A, typename B> void upmin(A& x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A& x, B v) { x = max(x, (A)v); }
template<typename A> A reversed(const A& a) { A b = a; reverse(all(b)); return b; }

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1};
const VLL dj = {1, -1, 0, 0, -1, -1, 1, 1};
const VLL mods = {1'000'000'007, 998'244'353, 1'000'000'207, 1'000'003};
const ll mod = mods[0];
const ll inf = (ll)1e18 + 5;
const db eps = 1e-10;
const db pi = acos(0) * 2;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// clang-format on

struct Game {
    VVLL board;
    Game() : board(4, VLL(4, 0)) {
        //
    }

    void moveDir(char c) {
        string s = "LDRU";
        move(s.find(c));
    }

    void move(ll d) {
        VVLL result = board;

        rep(_, 0, d) result = rotate(result);
        result = mergeLeft(result);
        rep(_, 0, 4 - d) result = rotate(result);

        board = result;
    }

    VVLL rotate(const VVLL& A) {
        VVLL once(4, VLL(4));
        rep(i, 0, 4) {
            rep(j, 0, 4) {
                once[i][j] = A[3 - j][i];
            }
        }
        return once;
    }

    VVLL mergeLeft(VVLL A) {
        rep(i, 0, 4) {
            A[i] = mergeLeft(A[i]);
        }
        return A;
    }

    VLL mergeLeft(VLL A) {
        ll prev = -1;
        VLL res;
        fe(a, A) {
            if (a == 0) continue;
            if (prev == a) {
                res.push_back(prev + a);
                prev = -1;
            } else {
                if (prev != -1) res.push_back(prev);
                prev = a;
            }
        }
        if (prev != -1) res.push_back(prev);

        while (res.size() < 4) res.push_back(0);
        return res;
    }
};

void solve() {
    VVLL A(4, VLL(4));
    rep(i, 0, 4) {
        rep(j, 0, 4) {
            cin >> A[i][j];
        }
    }
    Game game;
    game.board = A;

    fe(b, game.board) debug(b);

    rep(i, 0, 4) {
        game.move(i);
        debug("");
        fe(b, game.board) debug(b);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}
