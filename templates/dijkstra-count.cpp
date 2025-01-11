namespace DIJ {
const ll inf = 1e18;
vector<ll> dist, cnt;  // dist, num ways to get there

void solve(const vector<vector<PLL>>& E, const ll s) {
    const ll n = E.size();

    // edge PLL: to, weight
    // todo PLL: dist, at

    // init structures
    dist.assign(n, inf);
    cnt.assign(n, -1);
    set<PLL> pq;  // dist, at

    // init s
    dist[s] = 0;
    cnt[0] = 1;
    pq.insert({0, s});
    while (pq.size()) {
        const auto t = *pq.begin();
        pq.erase(t);

        const ll curDist = t.first;
        const ll at = t.second;
        if (dist[at] < curDist) continue;
        // unpacking - we are promised that dist is the best distance

        for (const auto& edge : E[at]) {
            const ll to = edge.first;
            const ll weight = edge.second;

            if (curDist + weight < dist[to]) {
                pq.insert({curDist + weight, to});
                dist[to] = curDist + weight;
                cnt[to] = cnt[at];
            } else if (curDist + weight == dist[to]) {
                cnt[to] += cnt[at];
                // cnt[to] %= mod;
            }
        }
    }
}
}  // namespace DIJ
