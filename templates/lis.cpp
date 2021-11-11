
namespace LIS {
VLL dp;  // dp[i] is the smallest number ending in a subsequence of length (i+1)
VLL ind;  // ind[i] is the index of dp[i]
VLL par;  // par[i] is the parent index of ind[i]

ll bs(ll x) {
    // Finds highest index with dp[j] < x
    ll L = 0, R = sz(dp) - 1;
    ll ans = -1;
    while (L <= R) {
        ll M = (L + R) / 2;
        if (dp[M] < x) {
            upmax(ans, M);
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    return ans;
}

void build(const VLL& A) {
    dp.clear();
    par.assign(sz(A), -1);

    rep(i, 0, sz(A)) {
        const ll a = A[i];

        if (dp.size() == 0) {
            par[i] = -1;
            dp.pb(a);
            ind.pb(i);
        } else if (a > dp.back()) {
            par[i] = ind[sz(dp) - 1];
            dp.pb(a);
            ind.pb(i);
        } else if (a < dp[0]) {
            par[i] = -1;
            dp[0] = a;
            ind[0] = i;
        } else {
            // what do we do with element a?
            // we find the largest index with dp[j] < a
            ll j = bs(a);
            par[i] = ind[j];
            dp[j + 1] = a;
            ind[j + 1] = i;
        }
    }
}

VLL construct(const VLL& A) {
    assert(sz(dp));
    VLL ans;
    ll cur = ind.back();
    while (cur != -1) {
        ans.pb(A[cur]);
        cur = par[cur];
    }
    reverse(all(ans));
    return ans;
}
}  // namespace LIS