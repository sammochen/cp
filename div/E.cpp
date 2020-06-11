#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

VLL p; 

ll getp(ll x) {
	if (p[x] == x) return x;
	p[x] = getp(p[x]);
	return p[x];
}

ll same(ll a, ll b);
void merge(ll a, ll b) {
	if (same(a,b)) return;
	p[getp(a)] = getp(b);
}

ll same(ll a, ll b) {
	return getp(a) == getp(b);
}

void init(ll n) {
	p.clear();
	p.resize(n);
	REP(i,0,n) p[i] = i;
}

void solve() {
    ll n;
    cin >> n;
    VVLL E(n, VLL(n, inf));

    vector<pair<ll,PLL>> edges;
    REP(i,1,n) {
        REP(j,0,i) {
            cin >> E[i][j];

            // first join the negatives
            if (E[i][j] < 0) edges.push_back({abs(E[i][j]), {i, j}});
        }
    }

    VLL cost(n); // cost of internal island, temporarily

    sort(edges.begin(), edges.end());

    init(n);
    for (auto e : edges) {
        if (same(e.second.first, e.second.second)) continue;
        cost[e.second.first] += e.first;
        merge(e.second.first, e.second.second);
    }

    VLL realcost(n);
    VLL parent(n);
    REP(i,0,n) {
        parent[i] = getp(i);
        realcost[getp(i)] += cost[i];
    }

    edges.clear();
    REP(i,1,n) {
        REP(j,0,i) {
            if (E[i][j] > 0) {
                ll ii = getp(i);
                ll jj = getp(j);
                ll cur = E[i][j] + realcost[ii] + realcost[jj];
                edges.push_back({cur, {ii, jj}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    init(n);
    ll ans = 0;
    for (auto e : edges) {
        if (same(e.second.first, e.second.second)) continue;
        ans += e.first;
        merge(e.second.first, e.second.second);
    }

    REP(i,0,n) {
        if (getp(parent[i]) != getp(parent[0])) {
            cout << "impossible" << endl;
            return;
        }
    }
    cout << ans << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}