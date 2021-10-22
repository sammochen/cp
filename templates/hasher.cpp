struct hasher {
    string s;
    ll mod, seed = 31;
    /**
     * [3,2,1,4], seed = 10
     * pre = [0,3,23,123,4123]
     */
    VLL pow, pre;

    ll get_value(char c) {
        ll value = c - 'a' + 1;
        assert(value > 0 && value < seed);
        return value;
    }

    hasher(const string& s, ll mod) {
        this->s = s;
        this->mod = mod;
        ll n = lg(s);
        pow.resize(n + 1);
        pre.resize(n + 1);

        pow[0] = 1;
        rep(i, 0, n) {
            pow[i + 1] = pow[i] * seed % mod;
            pre[i + 1] = pre[i] + get_value(s[i]) * pow[i];
        }
    }

    ll substr_hash(ll i, ll j) {
        ll n = lg(s);
        assert(!ob(i, n) && !ob(j, n));

        ll diff = pre[j + 1] - pre[i];
        makemod(diff, mod);
        diff *= powmod(pow[i], mod - 2, mod);
        diff %= mod;
        return diff;
    }
};