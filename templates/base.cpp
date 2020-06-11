ll value(string s, ll base) {
	ll b = 1;
	ll ans = 0;
	rrep(i, s.length() - 1, 0) {
		ll x;
		if (s[i] >= '0' && s[i] <= '9') {
			x = s[i] - '0';
		} else {
			x = s[i] - 'A' + 10;
		}
		if (x >= base) return -1;
		ans += x * b;
		b *= base;
	}
	return ans;
}
