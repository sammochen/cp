
struct DSU {
    const ll n;
    VLL par;
    ll numComponents;

    DSU(ll n) : n(n), numComponents(n) {
        par.resize(n);
        for (ll i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    ll root(ll x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    ll same(ll a, ll b) {
        return root(a) == root(b);
    }

    void merge(ll a, ll b) {
        if (same(a, b)) return;
        par[root(b)] = root(a);
        numComponents--;
    }
};
