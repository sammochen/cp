
namespace LIS {
VLL dp;   // dp[i] is the smallest number ending in a subsequence of length (i+1)
VLL ind;  // ind[i] is the index of dp[i]
VLL par;  // par[i] is the parent index of ind[i]

ll correctOrder(ll a, ll b) {
    return a <= b;
}

ll bs(ll x) {
    // Finds highest index x can go after
    ll L = 0, R = dp.size() - 1;
    ll ans = -1;
    while (L <= R) {
        ll M = (L + R) / 2;
        if (correctOrder(dp[M], x)) {
            ans = max(ans, M);
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    return ans;
}

ll build(const VLL& A) {
    const ll n = A.size();
    dp.clear();
    ind.clear();
    par.assign(n, -1);

    rep(i, 0, n) {
        const ll x = A[i];

        if (dp.size() == 0 || correctOrder(dp.back(), x)) {
            // can append to end
            par[i] = dp.size() == 0 ? -1 : ind[dp.size() - 1];
            dp.push_back(x);
            ind.push_back(i);
        } else if (x < dp[0]) {
            // new lowest value
            par[i] = -1;
            dp[0] = x;
            ind[0] = i;
        } else {
            // find the largest index j that x can go after
            const ll j = bs(x);
            par[i] = ind[j];
            dp[j + 1] = x;
            ind[j + 1] = i;
        }
    }

    return dp.size();  // length of LIS
}

VLL construct(const VLL& A) {
    // should be called after build
    VLL ans;
    ll cur = ind.back();
    while (cur != -1) {
        ans.push_back(A[cur]);
        cur = par[cur];
    }
    reverse(all(ans));
    return ans;
}
}  // namespace LIS
