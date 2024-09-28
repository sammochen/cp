// longest matching prefix
VLL kmp(const string& s) {
    ll n = s.length();
    VLL k(n);
    rep(i, 1, n) {
        ll prev = k[i - 1];
        while (prev && s[i] != s[prev]) {
            prev = k[prev - 1];
        }
        k[i] = prev + (s[i] == s[prev]);
    }
    return k;
}
