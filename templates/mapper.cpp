// maps values to 0-based id
struct Mapper {
    ll cur = 0;
    umap<ll, ll> to;

    ll get(ll x) {
        if (to.find(x) == to.end()) {
            to[x] = cur;
            cur++;
        }

        const auto& it = to.find(x);
        assert(it != to.end());
        return it->second;
    }
};