ll getValue(const string& s, const ll base) {
    ll n = s.size(), ans = 0;
    assert(n);
    rrep(i, 0, n) {
        const ll digit = s[i] >= '0' && s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10;
        assert(digit >= 0 && digit < base);
        ans *= base;
        ans += digit;
    }
    return ans;
}
