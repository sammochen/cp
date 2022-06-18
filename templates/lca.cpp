
namespace LCA {
ll n, k;
VVLL E;

VVLL par;  // par[i][k] gives the 2^k parent, or -1 if too high
VLL depth, timeIn, timeOut;
ll curTime = 0;

void dfs(const ll at, const ll prev, const ll d) {
    par[at][0] = prev, depth[at] = d, timeIn[at] = curTime++;
    fe(to, E[at]) {
        if (to == prev) continue;
        dfs(to, at, d + 1);
    }
    timeOut[at] = curTime++;
}

// checks if i is j's parent
ll isPar(ll i, ll j) {
    return timeIn[i] <= timeIn[j] && timeOut[i] >= timeOut[j];
}

ll distPar(ll i, ll j) {
    // return dist knowing that isPar(i, j)
    assert(isPar(i, j));

    // try raise j as high as possible
    ll ans = 0;
    rrep(d, k - 1, 0) {
        const ll jj = par[j][d];

        // if j goes too far, don't do it
        if (jj == -1 || isPar(jj, i)) continue;

        ans += tp(d);
        j = jj;
    }
    ans += 1;
    return ans;
}

ll lca(ll i, ll j) {
    if (i == j) return i;
    if (isPar(i, j)) return i;
    if (isPar(j, i)) return j;

    // try increase i as high as possible without being j's parent
    rrep(d, k - 1, 0) {
        ll ii = par[i][d];
        if (ii == -1 || isPar(ii, j)) continue;
        i = ii;
    }
    return par[i][0];
}

ll dist(ll i, ll j) {
    ll p = lca(i, j);
    return distPar(p, i) + distPar(p, j);
}

void build(ll n, const VVLL& E) {
    LCA::n = n;
    LCA::E = E;
    LCA::k = log2(n) + 2;  // safety

    par.resize(n, VLL(k));
    depth.resize(n), timeIn.resize(n), timeOut.resize(n);
    curTime = 1;
    dfs(0, -1, 0);

    // binary lifting
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
