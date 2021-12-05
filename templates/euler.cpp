namespace EulerPath {
unordered_map<int, unordered_set<int>> E;
unordered_map<int, int> deg;  // deg = out - in

vector<int> path;

void reset() {
    E.clear(), deg.clear(), path.clear();
}

void addEdge(int a, int b) {
    E[a].insert(b);
    deg[a]++;
    deg[b]--;
}

void dfs(int at) {
    auto& S = E[at];

    while (S.size()) {
        int to = *S.begin();

        E[at].erase(E[at].find(to));
        dfs(to);
    }
    path.push_back(at);
}

void build() {
    for (auto s : deg) {
        if (s.second % 2 == 1) {
            dfs(s.first);
            reverse(path.begin(), path.end());
            return;
        }
    }
    dfs(deg.begin()->first);
    reverse(path.begin(), path.end());
}
}  // namespace EulerPath
