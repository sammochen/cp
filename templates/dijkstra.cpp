struct edge {
    ll to, d;
};

struct todo {
    ll v, d;
};

bool operator<(const todo & a, const todo & b) {
    return a.d > b.d;
}

VLL dijkstra(vector<vector<edge>> & E, ll s) {
    VLL d(E.size(), inf);
    d[s] = 0;
    priority_queue<todo> pq;

    pq.push({s, 0});
    while (pq.size()) {
        todo t = pq.top();
        pq.pop();

        for (edge e : E[t.v]) {
            if (d[t.v] + e.d < d[e.to]) {
                pq.push({e.to, d[t.v] + e.d});
                d[e.to] = d[t.v] + e.d;
            }
        }
    }

    return d;
}

