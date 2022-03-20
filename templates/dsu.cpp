
struct DSU {
    const ll n;
    vector<ll> par;

    DSU(ll n) : n(n) {
        par.resize(n);
        for (ll i = 0, i < n; i++) {
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
