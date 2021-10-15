VLL zf(string s) {
    ll n = s.length();
    VLL z(n);
    ll l = 0, r = 0;
    REP(i, 1, n) {
        // if within the bound, update the z value
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        // push it up if you can - this might push the r value up
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        // if the value exceeds the bounds, update bound
        if (i + z[i] >= r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}