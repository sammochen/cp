// bit vector
template <int N, int W>
struct BV {
    const ll ones = (1 << W) - 1;  // width-lengthed 1s
    unsigned long long mask = 0;   // data repr

    void set(const ll ind, const ll val) {
        assert(ind >= 0 && ind < N);
        assert(val >= 0 && val < (1 << W));

        mask &= ~(ones << (ind * W));  // set to 0
        mask |= (val << (ind * W));    // set to val
    }

    const ll get(const ll ind) const {
        return (mask >> (ind * W)) & ones;
    }

    const ll compr(const ll pow) const {
        ll p = 1;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += get(i) * p;
            p *= pow;
        }
        return res;
    }
};