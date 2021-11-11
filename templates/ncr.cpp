
namespace Comb {
const ll nax = 1e5;

ll F[nax];
ll INVF[nax];

ll ready = 0;

void init() {
    if (ready) return;
    ready = 1;
    F[0] = 1;
    rep(i, 0, nax) {
        if (i == 0) {
            F[i] = 1;
        } else {
            F[i] = F[i - 1] * i % mod;
        }
        INVF[i] = powmod(F[i], mod - 2, mod);
    }
}

ll ncr(ll n, ll r) {
    init();

    assert(n >= 0 && n < nax && r >= 0 && r <= n);

    ll ans = F[n];   // times n!
    ans *= INVF[r];  // div r!
    ans %= mod;
    ans *= INVF[n - r];  // div (n-r)!
    ans %= mod;
    return ans;
}
}  // namespace Comb