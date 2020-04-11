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

struct edge {
    ll a,b,d;
};

VLL p; 

ll getp(ll x) {
    if (p[x] == x) return x;
    p[x] = getp(p[x]);
    return p[x];
}

void merge(ll a, ll b) {
    p[getp(a)] = getp(b);
}

ll same(ll a, ll b) {
    return getp(a) == getp(b);
}

vector<vector<edge>> kruskals(vector<edge> & edgelist, ll n) {
    p.clear();
    p.resize(n);
    REP(i,0,n) p[i] = i;

    vector<vector<edge>> adjlist(n);

   
    for (edge e: edgelist) {
        if (same(e.a, e.b)) continue;
        merge(e.a, e.b);
        adjlist[e.a].push_back({e.a, e.b, e.d});
        adjlist[e.b].push_back({e.b, e.a, e.d});
    }

    return adjlist;
}
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<edge> edgelist(m);
    REP(i,0,m) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        edgelist.push_back({a,b,w});
    }

    // set up a minimum spanning tree - because it is never optimal to choose the highest ones when you dont need to
    vector<vector<edge>> adjlist = kruskals(edgelist);

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}