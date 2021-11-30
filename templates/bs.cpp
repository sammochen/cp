typedef long long ll;

ll ok(ll M) {
    // see if M works
}

ll findMax(ll L, ll R) {
    // maximise
    ll ans = -1e18;
    while (L <= R) {
        ll M = (L + R) / 2;

        if (ok(M)) {
            ans = max(ans, M);
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
    return ans;
}

ll findMin(ll L, ll R) {
    // minimise
    ll ans = 1e18;
    while (L <= R) {
        ll M = (L + R) / 2;

        if (ok(M)) {
            ans = min(ans, M);
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    return ans;
}