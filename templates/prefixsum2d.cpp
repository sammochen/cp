
struct PrefixSum2D {
    const ll n, m;
    const VVLL& A;
    const VVLL pre;

    VVLL calc(const VVLL& A) {
        ll n = A.size(), m = A[0].size();
        VVLL pre(n + 1, VLL(m + 1));
        rep(i, 0, n) {
            rep(j, 0, m) {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + A[i][j];
            }
        }
        return pre;
    }

    PrefixSum2D(const VVLL& A) : n(A.size()), m(A[0].size()), A(A), pre(calc(A)) {}
    ll sum(ll i1, ll j1, ll i2, ll j2) {
        // both inclusive
        if (i1 > i2 || j1 > j2) {
            // invalid
            assert(false);
        }

        return pre[i2 + 1][j2 + 1] - pre[i1][j2 + 1] - pre[i2 + 1][j1] + pre[i1][j1];
    }
};
