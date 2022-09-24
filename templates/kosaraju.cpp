
// Kosaraju's SCC
namespace Kosaraju {

VLL order;
VLL vis;
VVLL comps;

void dfs1(ll at, VVLL& E) {
    if (vis[at]) return;
    vis[at] = 1;
    for (ll to : E[at]) {
        dfs1(to, E);
    }
    order.push_back(at);  // exit times
}

void dfs2(ll at, VVLL& revE, VLL& comp) {
    if (vis[at]) return;
    vis[at] = 1;
    comp.push_back(at);
    for (ll to : revE[at]) {
        dfs2(to, revE, comp);
    }
}

void build(ll n, VVLL& E) {
    order.clear();
    vis.clear();
    comps.clear();

    vis.assign(n, 0);
    rep(i, 0, n) {
        dfs1(i, E);
    }

    VVLL revE(n);
    rep(i, 0, n) {
        fe(to, E[i]) {
            revE[to].push_back(i);
        }
    }

    reverse(all(order));
    vis.assign(n, 0);
    for (auto o : order) {
        if (vis[o]) continue;
        VLL comp;
        dfs2(o, revE, comp);
        comps.emplace_back(move(comp));
    }

    // the comps will be in topological order
}
}  // namespace Kosaraju
