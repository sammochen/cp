namespace DIJ {
const ll inf = 1e18;
vector<ll> d, cnt;  // dist, num ways to get there

void solve(const vector<vector<PLL>>& E, const ll s) {
    const ll n = E.size();

    // edge PLL: to, weight
    // todo PLL: dist, at

    // init structures
    d.assign(n, inf);
    cnt.assign(n, -1);
    set<PLL> pq;  // dist, at

    // init s
    d[s] = 0;
    cnt[0] = 1;
    pq.insert({0, s});
    while (pq.size()) {
        const auto t = *pq.begin();
        pq.erase(t);

        const ll dist = t.first;
        const ll at = t.second;
        if (d[at] < dist) continue;

        for (const auto& edge : E[at]) {
            const ll to = edge.first;
            const ll weight = edge.second;

            if (dist + weight < d[to]) {
                pq.insert({dist + weight, to});
                d[to] = dist + weight;
                cnt[to] = cnt[at];
            } else if (dist + weight == d[to]) {
                cnt[to] += cnt[at];
                // cnt[to] %= mod;
            }
        }
    }
}
}  // namespace DIJ
