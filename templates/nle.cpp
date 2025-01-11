
using ll = long long;
ll inf = 1e18;

// Returns the index of the next smallest element
vector<ll> nextSmallest(vector<ll>& A) {
    ll n = A.size();
    vector<pair<ll, ll>> st;
    st.push_back({-inf, n});  // ! CHANGE THIS

    vector<ll> ans(n, -1);
    for (ll i = n - 1; i >= 0; i--) {
        while (A[i] <= st.back().first) {  // ! CHANGE THIS for inc/noninc
            st.pop_back();
        }

        ans[i] = st.back().second;
        st.push_back({A[i], i});
    }
    return ans;
}

vector<ll> prevSmallest(vector<ll>& A) {
    ll n = A.size();
    vector<pair<ll, ll>> st;
    st.push_back({-inf, -1});  // ! CHANGE THIS

    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; i++) {
        while (A[i] <= st.back().first) {  // ! CHANGE THIS for inc/noninc
            st.pop_back();
        }

        ans[i] = st.back().second;
        st.push_back({A[i], i});
    }
    return ans;
}
