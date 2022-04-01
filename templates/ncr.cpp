
namespace NCR {
const ll nax = 1e5 + 5;

ll F[nax];
ll INVF[nax];

ll inited = 0;
void init() {
    if (inited) return;
    inited = 1;
    rep(i, 0, nax) {
        F[i] = (i == 0) ? 1 : F[i - 1] * i % mod;
        INVF[i] = powmod(F[i], mod - 2, mod);
    }
}

ll ncr(ll n, ll r) {
    init();
    assert(n >= 0 && n < nax && r >= 0 && r <= n);
    return F[n] * INVF[r] % mod * INVF[n - r] % mod;
}
}  // namespace NCR
