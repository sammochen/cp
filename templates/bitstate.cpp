// bit vector
template <int Base>
struct Bitstate {
    ll repr = 0;
    mutable vector<ll> pows;

    Bitstate() {
        pows.assign(30, -1);
        pows[0] = 1;
    }

    ll base_pow(ll ind) const {
        return (pows[ind] == -1) ? pows[ind] = base_pow(ind - 1) * Base : pows[ind];
    }

    void set(ll ind, ll val) {
        repr += (val - get(ind)) * base_pow(ind);
    }

    ll get(ll ind) const {
        return (repr / base_pow(ind)) % Base;
    }

    vector<ll> to_vector(ll n) const {
        vector<ll> ans(n);
        for (ll i = 0; i < n; i++) ans[i] = get(i);
        return ans;
    }
};
