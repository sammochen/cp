// clang-format off

#ifdef SAM
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define fe(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define lg(x) (ll)x.length()
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
	string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

// clang-format on

namespace Dinic {
struct edge {
    ll from, to, cap;
    edge(ll a, ll b, ll c) : from(a), to(b), cap(c) {}
    edge() : from(0), to(0), cap(0) {}
};

const ll NAX = 450, MAX = 20050, SOURCE = NAX - 1, SINK = NAX - 2;
ll cnt = 0;

vector<ll> g[NAX];  // g keeps the indices of the edges
edge e[MAX];

// Resets everything
void clear() {
    cnt = 0;
    rep(i, 0, NAX) g[i].clear();
    rep(i, 0, MAX) e[i] = edge();
}

// Adds an edge from u to v with cap
void addEdge(ll u, ll v, ll cap) {
    // e[cnt] is the current edge and e[cnt^1] is the inverse edge
    e[cnt] = edge(u, v, cap);
    g[u].push_back(cnt);

    e[cnt ^ 1] = edge(v, u, 0);
    g[v].push_back(cnt ^ 1);

    cnt += 2;
}

ll lvl[NAX];  // Level graph of BFS. Distance from source.
ll dfsStart[NAX];

// Performs BFS from source. Returns true if there is a path
bool bfs(ll start = SOURCE) {
    memset(lvl, -1, sizeof(lvl));
    memset(dfsStart, 0, sizeof(dfsStart));

    lvl[start] = 0;
    queue<ll> Q;
    Q.push(start);

    while (Q.size()) {
        ll at = Q.front();
        Q.pop();

        // For each edge outwards
        for (auto to : g[at]) {  // 'to' is the index
            auto& E = e[to];
            if (E.cap > 0) {  // If there is an edge
                if (lvl[E.to] == -1) {
                    lvl[E.to] = lvl[at] + 1;
                    Q.push(E.to);
                }
            }
        }
    }
    return lvl[SINK] != -1;
}

// Performs DFS. This step brute force goes through the graph and sees if some
// flow can go from the source to the sink If there is ever a path from source
// to sink, it returns the cap and updates
ll dfs(ll at, ll cap) {
    if (cap == 0 || at == SINK) return cap;

    ll ans = 0;
    // For each edge (no repeat edges, ever)
    for (; dfsStart[at] < g[at].size(); dfsStart[at]++) {
        ll to = g[at][dfsStart[at]];

        // If the next vertex is positive in distance
        if (lvl[e[to].to] == lvl[at] + 1) {
            // The cap if we continue there
            ll delta = dfs(e[to].to, min(e[to].cap, cap));
            ans += delta;
            cap -= delta;
            e[to].cap -= delta;
            e[to ^ 1].cap += delta;
            if (cap == 0) break;
        }
    }
    return ans;
}

ll dinic() {
    ll ans = 0;
    while (bfs()) {
        ans += (dfs(SOURCE, inf));
    }
    return ans;
}
}  // namespace Dinic

void solve() {
    ll m;
    cin >> m;

    Dinic::clear();

    rep(i, 0, m) {
        string a, b;
        ll c;
        cin >> a >> b >> c;

        Dinic::addEdge(a[0] - 'A', b[0] - 'A', c);
    }

    Dinic::addEdge(Dinic::SOURCE, 'S' - 'A', inf);
    Dinic::addEdge('T' - 'A', Dinic::SINK, inf);

    cout << Dinic::dinic() << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}