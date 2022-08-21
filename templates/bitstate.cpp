
template <typename WIDTH>
struct bitstate {
    constexpr PER_LL = 62 / WIDTH;
    VLL data;  // underlying data

    void resize(ll n) {
        data.resize(rup(n, PER_LL));
    }

    pair<int, int> getInd(ll ind) const {
        ll i = ind / PER_LL, j = ind % PER_LL;
        return {i, j};
        ll num = data[i];
        // get the j'th area
    }

    ll get(ll ind) const {
        auto [i, j] = getInd(ind);
        ll& num = data[i];
        return (num >> (WIDTH * j)) % tp(WIDTH);
    }

    void setbit(ll i, ll j, ll v) {
        if (v) {
            num |= tp(j);
        } else {
            num &= ~tp(j);
        }
    }

    void set(ll ind, ll value) {
        auto [i, j] = getInd(ind);
        auto& num = data[i];

        rep(bit, 0, WIDTH) {
            if (tp(bit) & value) {
                num |= tp(j * WIDTH + bit);
            } else {
                num &= ~tp(j * WIDTH + bit);
            }
        }
    }
};
