ll nax = 1e5;

VLL F(nax, -1);
VLL INVF(nax, -1);

ll f(ll x) {
    if (F[x] != -1) return F[x];
    if (x == 0) return 1;
    F[x] = f(x - 1) * x % mod;
    return F[x];
}

ll invf(ll x) {
    if (INVF[x] != -1) return INVF[x];
    INVF[x] = powmod(f(x), mod - 2, mod);
    return INVF[x];
}

ll ncr(ll n, ll r) {
    // n! / r! / (n-r)!
    ll ans = f(n);
    ans *= invf(r);
    ans %= mod;
    ans *= invf(n - r);
    ans %= mod;
    return ans;
}
