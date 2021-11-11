
struct DSU {
    const ll n;
    VLL par;

    DSU(ll n) : n(n) {
        par.resize(n);
        rep(i, 0, n) {
            par[i] = i;
        }
    }

    ll root(ll x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    ll same(ll a, ll b) {
        return root(a) == root(b);
    }

    void merge(ll a, ll b) {
        if (same(a, b)) return;
        par[root(b)] = root(a);
    }
};
