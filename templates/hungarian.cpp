namespace Hungarian {
// http://e-maxx.ru/algo/assignment_hungary
VLL send(ll n, ll m, VVLL a) {
    VLL u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for (ll i = 1; i <= n; ++i) {
        p[0] = i;
        ll j0 = 0;
        VLL minv(m + 1, inf);
        VLL used(m + 1, false);
        do {
            used[j0] = true;
            ll i0 = p[j0], delta = inf, j1;
            for (ll j = 1; j <= m; ++j)
                if (!used[j]) {
                    ll cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
            for (ll j = 0; j <= m; ++j)
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            ll j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    VLL ans(n + 1);
    for (ll j = 1; j <= m; ++j) {
        ans[p[j]] = j;
    }
    return ans;
}

VLL solve(VVLL A) {
    // move to 1-indexing
    ll n = sz(A), m = sz(A[0]);
    assert(n <= m);
    VVLL B(n + 1, VLL(m + 1));
    rep(i, 0, n) {
        rep(j, 0, m) {
            B[i + 1][j + 1] = A[i][j];
        }
    }

    // adjust back to 0-indexing
    auto res = send(n, m, B);
    VLL adjusted;
    rep(i, 1, sz(res)) {
        adjusted.pb(res[i] - 1);
    }
    return adjusted;
}

}  // namespace Hungarian
