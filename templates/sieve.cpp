
namespace Sieve {
const ll nax = 1005;
ll prevPrime[nax * nax];

void init() {
    mst(prevPrime, -1);
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
    return prevPrime[x] == x;
}
}  // namespace Sieve