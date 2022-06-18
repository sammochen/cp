namespace PermCycles {
VLL A;
ll n;

VLL vis;
VLL path;
VVLL paths;

void dfs(ll at, VLL& A) {
    if (vis[at]) return;
    vis[at] = 1;
    path.push_back(at);

    dfs(A[at], A);
}

void build(const VLL& B) {
    A = B;
    n = A.size();

    vis.assign(n, 0);
    path.clear();
    paths.clear();

    rep(i, 0, n) {
        if (!vis[i]) {
            path.clear();
            dfs(i, A);
            paths.push_back(path);
        }
    }
}
}  // namespace PermCycles
