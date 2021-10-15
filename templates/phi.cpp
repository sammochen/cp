

ll nax = 1005;
VLL p(nax* nax, 1);
VLL P;

void init() {
    p[0] = 0;
    p[1] = 0;

    for (ll x = 2; x < nax * nax; x++) {
        if (p[x] == 0) {
            continue;
        }

        P.push_back(x);

        for (ll f = x; x * f < nax * nax; f++) {
            p[x * f] = 0;
        }
    }
}

// The number of y < x where y is relatively prime to x
ll phi(ll x) {
    // find all prime factors, then it is x * product(1 - 1/p)
    ll ans = x;
    rep(i, 0, P.size()) {
        if (P[i] * P[i] > x) break;
        if (x % P[i] == 0) {
            ans *= (P[i] - 1);
            ans /= P[i];
        }
        while (x % P[i] == 0) {
            x /= P[i];
        }
    }

    if (x != 1) {
        ans *= (x - 1);
        ans /= x;
    }
    return ans;
}
