#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

void bye() {
    cout << "MISTAKE" << endl;
    exit(0);
}

void solve() {
	ll n;
    cin >> n;

    VLL deg(1<<n);
    vector<set<ll>> E(1<<n);

    REP(i,0,(1<<n)-1) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        E[a].insert(b);
        E[b].insert(a);

        deg[a]++;
        deg[b]++;
    }

    set<ll> layer;
    REP(i,0,(1<<n)) layer.insert(i);

    while (sz(layer) > 2) {
        set<ll> next;
        map<ll,ll> used;
        
        for (ll at : layer) {
            if (deg[at] == 0) bye();
            if (used[at]) continue;
            if (deg[at] != 1) continue;

            ll to = *E[at].begin();
            if (used[to]) bye();
            used[to] = 1;

            deg[to]--;
            E[to].erase(at);

            next.insert(to);
        }

        layer = next;
    }

    if (sz(layer) != 2) bye();
    for (ll x : layer) {
        if (deg[x] != 1) bye();
    }
    
    cout << "OK" << endl;
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}