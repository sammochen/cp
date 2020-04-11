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

typedef int ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e9 + 7;
VLL bfs(VVLL & E, VVLL & W, VVLL & costs, ll s, ll limit) {
    VLL D(E.size(), inf);
    queue<ll> Q;
    D[s] = 0;
    Q.push(s);
    while (Q.size()) {
        ll at = Q.front();
        Q.pop();
        for (ll to : E[at]) {
            if (costs[at][to] > limit) continue;

            if (W[at][to] <= 0) continue;
            if (D[to] != inf) continue;
            D[to] = D[at] + 1;
            Q.push(to); 
        }
    }
    return D;
}

// returns the maxflow possible from at to t
ll dfs(VVLL & E, VVLL & W, VVLL & costs, VLL & D, ll at, ll t, ll f, ll limit) {
    if (at == t) {
        return f;
    }

    for (ll to : E[at]) {
        if (costs[at][to] > limit) continue;

        if (W[at][to] > 0 && D[to] == D[at] + 1) {
            ll flow = dfs(E, W, costs, D, to, t, min(f, W[at][to]), limit);
            if (flow > 0) {
                W[at][to] -= flow;
                W[to][at] += flow;
                return flow;
            }
        }
    }
    return 0;
}

// returns the max flow
ll dinic(VVLL E, VVLL W, VVLL & costs, ll s, ll t, ll limit) {
    ll mf = 0;
    while (1) {
        // do bfs
        VLL D = bfs(E, W, costs, s, limit);
        if (D[t] == inf) return mf;

        // do dfs 
        while (1) {
            ll f = dfs(E,W,costs,D,s,t,inf, limit);
            mf += f;
            if (f == 0) break;
        }
    }
    return mf;
}

void addedge(VVLL & E, VVLL & W, VVLL &costs, ll a, ll b, ll w, ll c) {
    E[a].push_back(b);
    E[b].push_back(a);
    W[a][b] = w;
    costs[a][b] = c;
    costs[b][a] = c;
}

ll n, d, m, test = 1;

ll state(ll city, ll day) {
    return city * (d+1) + day;
}

void solve() {
    cin >> n >> d >> m;
    ll states = n*(d+1);
    ll s = states + 3;
    ll t = state(n-1, d);

    VVLL E(states + 5);
    VVLL W(states + 5, VLL(states + 5));
    VVLL costs(states + 5, VLL(states + 5));
    set<ll> prices;
    REP(i,0,m) {
        ll u, v, c, p, e;
        cin >> u >> v >> c >> p >> e;
        addedge(E, W, costs, state(u-1,e), state(v-1,e+1), c, p);
        prices.insert(p);
    }

    ll total = 0;
    REP(i,0,n) {
        ll x;
        cin >> x;
        addedge(E, W, costs, s, state(i, 0), x, 0);
        total += x;
    }

    REP(i,0,n) {
        REP(j,0,d) {
            addedge(E, W, costs, state(i,j), state(i,j+1), inf, 0);
        }
    }

    if (dinic(E, W, costs, s, t, 100005) != total) {
        printf("Case #%d: Impossible\n", test++);
        return;
    }

    VLL unique;
    for (ll p : prices) unique.push_back(p);
    ll L = 0, R = unique.size() - 1;
    while (L < R) {
        ll M = (L+R) / 2;       
        ll ans = dinic(E, W, costs, s, t, unique[M]);

        if (ans == total) {
            R = M;
        } else {
            L = M+1;
        }
    }
    printf("Case #%d: %d\n", test++, unique[L]);

}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}