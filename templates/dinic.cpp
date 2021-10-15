
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