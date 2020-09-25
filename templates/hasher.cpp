struct hasher {
	string s;
	ll mod;
	ll seed = 31;
	VLL pow, val;

	ll toll(char c) {
		return c - 'a' + 1;
	}
	hasher(string str, ll m = 1000000207) {
		s = str;
		mod = m;

		pow.resize(s.length() + 1);
		val.resize(s.length() + 1);
		pow[0] = 1;
		rep(i,0,s.length()) {
			val[i+1] = (val[i] + toll(s[i]) * pow[i] % mod) % mod;
			pow[i+1] = (pow[i] * seed) % mod;
		}
	}

	ll f(ll i, ll j) {
		ll diff = (val[j+1] - val[i] + mod) % mod;
		// times this by how far away i is! 
		diff *= pow[s.length() - i];
		diff %= mod;
		return diff;
	}
};

