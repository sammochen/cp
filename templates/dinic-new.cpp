struct DinicEdge {
    ll from, to, cap;
    DinicEdge() : from(0), to(0), cap(0) {}
    DinicEdge(ll a, ll b, ll c) : from(a), to(b), cap(c) {}
};

struct Dinic {
    const ll n, source, sink;
    vector<DinicEdge> edges;  // edge list
    VVLL E;                   // adj list

    Dinic(ll n) : n(n), source(n - 1), sink(n - 2), E(n) {}

    // Adds an edge from u to v with cap
    void addEdge(ll u, ll v, ll cap) {
        // forward edge
        edges.emplace_back(u, v, cap);
        E[u].push_back(edges.size() - 1);

        // backward edge (cap=0)
        edges.emplace_back(v, u, 0);
        E[v].push_back(edges.size() - 1);
    }

    void fromSource(ll v, ll cap) {
        return addEdge(source, v, cap);
    }

    void toSink(ll v, ll cap) {
        return addEdge(v, sink, cap);
    }

    // bfs
    VLL buildLevel(ll start, ll& ok) {
        VLL level(n, -1);  // Level graph of BFS. Distance from source.
        level.assign(n, -1);
        QLL Q;

        level[start] = 0;
        Q.push(start);

        while (Q.size()) {
            ll at = Q.front();
            Q.pop();

            for (auto toInd : E[at]) {
                auto& [at, to, cap] = edges[toInd];
                if (cap > 0 && level[to] == -1) {  // If there is an edge
                    level[to] = level[at] + 1;
                    Q.push(to);
                }
            }
        }

        ok = (level[sink] != -1);
        return level;
    }

    // Returns the max flow from at -> sink while only following level
    ll dfs(ll at, ll inFlow, VLL& dfsPointer, const VLL& level) {
        if (inFlow == 0 || at == sink) return inFlow;

        ll ans = 0;
        while (dfsPointer[at] < E[at].size()) {
            auto& edgeInd = E[at][dfsPointer[at]];
            auto& edge = edges[edgeInd];
            auto& oppEdge = edges[edgeInd ^ 1];

            // Only allowed to go in the direction of the bfs level graph
            if (level[edge.to] == level[at] + 1) {
                // The cap if we continue there
                ll outFlow = dfs(edge.to, min(edge.cap, inFlow), dfsPointer, level);

                ans += outFlow;
                inFlow -= outFlow;
                edge.cap -= outFlow;
                oppEdge.cap += outFlow;
            }

            // if inFlow is 0, we may not have exhausted the current dfsPointer so do not
            // increment the pointer
            if (inFlow == 0) break;
            dfsPointer[at]++;
        }
        return ans;
    }

    ll flow() {
        ll ans = 0;
        while (1) {
            ll ok;
            VLL level = buildLevel(source, ok);
            if (!ok) break;

            VLL dfsPointer(n, 0);
            ans += (dfs(source, inf, dfsPointer, level));
        };
        return ans;
    }

    // NOTE: To find the resulting flow values, look at the reverse edges's cap
    vector<DinicEdge> critEdges() {
        vector<DinicEdge> res;
        ll m = edges.size();
        rep(i, 0, m) {
            if (i % 2 == 1) continue;
            auto& edge = edges[i];
            if (edge.from == source || edge.to == source) continue;
            if (edge.from == sink || edge.to == sink) continue;

            if (edges[i].cap == 0 && edges[i ^ 1].cap == 1) {  // cap == 1!!
                res.push_back(edge);
            }
        }
        return res;
    }
};
