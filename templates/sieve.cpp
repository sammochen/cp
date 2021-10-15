ll nax = 1005;
VLL pp(nax* nax, -1);

void init() {
    for (ll x = 2; x < nax * nax; x++) {
        if (pp[x] != -1) {
            continue;
        }
        pp[x] = x;

        for (ll f = x; x * f < nax * nax; f++) {
            pp[x * f] = x;
        }
    }
}

VLL pf(ll x) {
    VLL ans;
    while (x > 1) {
        ans.pb(pp[x]);
        x /= pp[x];
    }
    return ans;
}