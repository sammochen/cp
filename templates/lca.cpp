
namespace LCA {
ll n, k;
VVLL E;

VVLL par;  // par[i][k] gives the 2^k parent, or -1 if too high
VLL depth;
VLL tin, tout;
ll cur_time = 0;

void dfs(const ll& at, const ll& from, const ll& d) {
    par[at][0] = from;
    depth[at] = d;
    tin[at] = cur_time++;

    fe(to, E[at]) {
        if (to == from) continue;
        dfs(to, at, d + 1);
    }

    tout[at] = cur_time++;
}

// checks if i is j's parent
ll is_par(ll i, ll j) {
    return tin[i] <= tin[j] && tout[i] >= tout[j];
}

ll dist_par(ll i, ll j) {
    assert(is_par(i, j));

    // try raise j until it is i

    ll ans = 0;
    rrep(d, k - 1, 0) {
        ll nextj = par[j][d];

        // if j goes too far, don't do it
        if (nextj == -1) continue;
        if (is_par(nextj, i)) continue;

        ans += tp(d);
        j = nextj;
    }
    ans += 1;
    return ans;
}

ll lca(ll i, ll j) {
    if (i == j) return i;
    if (is_par(i, j)) return i;
    if (is_par(j, i)) return j;

    // try increase i as high as possible without being j's parent
    rrep(d, k - 1, 0) {
        ll nexti = par[i][d];
        if (nexti == -1 || is_par(nexti, j)) continue;
        i = nexti;
    }
    return par[i][0];
}

void build(ll n, const VVLL& E) {
    LCA::n = n;
    LCA::E = E;
    LCA::k = log2(n) + 2;

    par.resize(n, VLL(k));
    depth.resize(n);
    tin.resize(n);
    tout.resize(n);
    cur_time = 1;
    dfs(0, -1, 0);

    rep(d, 1, k) {
        rep(i, 0, n) {
            if (par[i][d - 1] == -1) {
                par[i][d] = -1;
            } else {
                par[i][d] = par[par[i][d - 1]][d - 1];
            }
        }
    }
}

}  // namespace LCA