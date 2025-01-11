
struct DSU {
    const ll n;
    VLL par, sz;
    ll numComponents;

    DSU(ll n) : n(n), numComponents(n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);

        sz.assign(n, 0);
    }

    ll root(ll x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }

    ll same(ll a, ll b) {
        return root(a) == root(b);
    }

    ll merge(ll a, ll b) {
        if (same(a, b)) {
            return 0;
        }
        sz[root(a)] += sz[root(b)];
        par[root(b)] = root(a);
        numComponents--;
        return 1;
    }
};
