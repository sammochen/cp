
ll inf = 1e18;

// Returns the index of the next smallest element
vector<int> nextSmallest(vector<int>& A) {
    int n = A.size();
    vector<pair<int, int>> st;
    st.push_back({-inf, n});

    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (A[i] <= st.back().first) {
            st.pop_back();
        }

        ans[i] = st.back().second;
        st.push_back({A[i], i});
    }
    return ans;
}

vector<int> prevSmallest(vector<int>& A) {
    int n = A.size();
    vector<pair<int, int>> st;
    st.push_back({-inf, -1});

    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        while (A[i] <= st.back().first) {
            st.pop_back();
        }

        ans[i] = st.back().second;
        st.push_back({A[i], i});
    }
    return ans;
}
