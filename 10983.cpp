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
VLL bfs(VVLL & E, VVLL & W, ll s) {
    VLL D(E.size(), inf);
    queue<ll> Q;
    D[s] = 0;
    Q.push(s);
    while (Q.size()) {
        ll at = Q.front();
        Q.pop();
        for (ll to : E[at]) {
            if (W[at][to] <= 0) continue;
            if (D[to] != inf) continue;
            D[to] = D[at] + 1;
            Q.push(to); 
        }
    }
    return D;
}

// returns the maxflow possible from at to t
ll dfs(VVLL & E, VVLL & W, VLL & D, ll at, ll t, ll f) {
    if (at == t) {
        return f;
    }

    for (ll to : E[at]) {
        if (W[at][to] > 0 && D[to] == D[at] + 1) {
            ll flow = dfs(E, W, D, to, t, min(f, W[at][to]));
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
ll dinic(VVLL E, VVLL W, ll s, ll t) {
    ll mf = 0;
    while (1) {
        // do bfs
        VLL D = bfs(E, W, s);
        if (D[t] == inf) return mf;

        // do dfs 
        while (1) {
            ll f = dfs(E,W,D,s,t,inf);
            mf += f;
            if (f == 0) break;
        }
    }
    return mf;
}

void addedge(VVLL & E, VVLL & W, ll a, ll b, ll w) {
    E[a].push_back(b);
    E[b].push_back(a);
    W[a][b] = w;
}

ll n, d, m, test = 1;

ll state(ll city, ll day, ll one) {
    return (city*(d+2) + day) * 2 + one;
}

void solve() {
    cin >> n >> d >> m;

    VVLL edges(m, VLL(5)); // u, v, c passengers, p price, e evening
    VLL costs;
    REP(i,0,m) {
        REP(j,0,5) {
            cin >> edges[i][j];
        }
        costs.push_back(edges[i][3]);
    }

    VLL people(n); // the people that are already there
    ll total = 0;
    REP(i,0,n) {
        cin >> people[i];
        total += people[i];
    }

    sort(costs.begin(), costs.end());
    ll L = 0, R = costs.size() - 1;
    ll states = (n+1)*(d+2)*2;
    ll good = 0;
    while (L < R) {
        ll M = (L+R) / 2;       

        // do flow
        VVLL E(states + 5);
        VVLL W(states + 5, VLL(states + 5));
        REP(i,0,m) {
            if (edges[i][3] <= costs[M]) {
                addedge(E, W, state(edges[i][0] - 1, edges[i][4], 1), state(edges[i][1] - 1, edges[i][4] + 1, 0), edges[i][2]);
            }
        }

        // stay in the same city overnight, and over day
        REP(i,0,n) {
            REP(j,0,d+1) {
                addedge(E, W, state(i,j,0), state(i,j,1), total);
                addedge(E, W, state(i,j,1), state(i,j+1,0), total);
            }
        }

        ll s = states + 3;
        REP(i,0,n) {
            addedge(E, W, s, state(i,0,0), people[i]);
        }
        
        ll ans = dinic(E, W, s, state(n-1,d,1));

        if (ans == total) {
            good = 1;
            R = M;
        } else {
            L = M+1;
        }
    }

    if (!good) printf("Case #%lld: Impossible\n", test++);
    else printf("Case #%lld: %lld\n", test++, costs[L]);

}

signed main() {
	ll t = 1;
    cin >> t;
	REP(i,0,t) solve();
	return 0;
}