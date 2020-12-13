class DSU {
public:
    DSU(int n) {
        init(n);
    }
    vector<int> par;
    
    void init(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    
    int getp(int x) {
        if (par[x] == x) return x;
        return par[x] = getp(par[x]);
    }
    
    int same(int a, int b) {
        return getp(a) == getp(b);
    }
    
    void merge(int a, int b) {
        if (same(a, b)) return;
        par[getp(b)] = getp(a);
    }
};