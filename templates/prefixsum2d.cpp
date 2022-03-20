
struct PrefixSum2D {
    const int n, m;
    const vector<vector<int>>& A;
    const vector<vector<int>> pre;

    vector<vector<int>> calc(const vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> pre(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + A[i][j];
            }
        }
        return pre;
    }

    PrefixSum2D(const vector<vector<int>>& A) : A(A), n(A.size()), m(A[0].size()), pre(calc(A)) {}
    int sum(int i1, int j1, int i2, int j2) {
        // both inclusive
        assert(i1 <= i2 && j1 <= j2);
        return pre[i2 + 1][j2 + 1] - pre[i1][j2 + 1] - pre[i2 + 1][j1] + pre[i1][j1];
    }
};
