// Tarjan's SCC
namespace Tarjan {
ll cur_time;
VVLL scc;

VLL first;  // first time at a node, -1 if not vis
VLL low;    // lowest time the node can see
VLL curStack, onStack;

void dfs(ll at, VVLL& E) {
    first[at] = cur_time;
    low[at] = cur_time;
    curStack.push_back(at);
    onStack[at] = 1;
    cur_time++;

    for (ll to : E[at]) {
        if (first[to] == -1) {
            dfs(to, E);
            low[at] = min(low[at], low[to]);
        } else if (onStack[to]) {
            low[at] = min(low[at], first[to]);
        }
    }

    // the "top" node of a scc
    if (first[at] == low[at]) {
        scc.emplace_back();
        VLL& comp = scc.back();

        while (1) {
            ll last = curStack.back();
            comp.push_back(last);
            onStack[last] = 0;
            curStack.pop_back();
            if (last == at) break;
        }
    }
}

void build(ll n, VVLL& E) {
    cur_time = 1;
    scc.clear();

    first.assign(n, -1);
    low.assign(n, 0);
    onStack.assign(n, 0);
    curStack.clear();

    rep(i, 0, n) {
        if (first[i] == -1) dfs(i, E);
    }
}
}  // namespace Tarjan
