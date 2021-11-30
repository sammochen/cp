namespace Sieve {
const ll nax = 1005;
ll inited = 0;
ll prevPrime[nax * nax];

void init() {
    if (inited) return;
    inited = 1;

    memset(prevPrime, -1, sizeof(prevPrime));
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

ll isprime(ll x) {
    init();
    return prevPrime[x] == x;
}
}  // namespace Sieve