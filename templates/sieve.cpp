
namespace Sieve {
const ll nax = 1005;
ll inited = 0;
ll prevPrime[nax * nax];
ll phiMemo[nax * nax];

void init() {
    if (inited) return;
    inited = 1;

    memset(prevPrime, -1, sizeof(prevPrime));
    memset(phiMemo, -1, sizeof(phiMemo));
    for (ll x = 2; x < nax * nax; x++) {
        // not prime
        if (prevPrime[x] != -1) continue;

        // is prime
        prevPrime[x] = x;
        for (ll f = x; x * f < nax * nax; f++) {
            prevPrime[x * f] = x;
        }
    }
}

ll isPrime(ll x) {
    init();
    return prevPrime[x] == x;
}

umap<ll, ll> decomp(const ll x) {
    init();
    umap<ll, ll> ans;
    ll y = x;
    while (y > 1) {
        ll a = prevPrime[y];
        ans[a]++;
        y /= a;
    }
    return ans;
}

// The number of y < x where y is relatively prime to x
ll phi(ll x) {
    init();

    if (x <= 1) return 0;

    ll& ans = phiMemo[x];
    if (ans != -1) return ans;
    ans = x;
    auto M = decomp(x);
    for (auto p : M) {
        ans /= p.first;
        ans *= p.first - 1;
    }
    return ans;
}

}  // namespace Sieve
