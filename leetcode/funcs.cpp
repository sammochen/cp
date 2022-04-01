using ll = long long;

ll rup(ll a, ll b) {
    return a % b ? a / b + 1 : a / b;
}

int isvowel(char c) {
    return string("aeiou").find(c) != string::npos;
}

vector<vector<int>> toE(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> E(n);
    for (auto& e : edges) {
        E[e[0]].push_back(e[1]);
        E[e[1]].push_back(e[0]);
    }
    return E;
}

ll powmod(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll h = powmod(a, b / 2, m);
    ll ans = h * h % m;
    return b % 2 ? ans * a % m : ans;
}

vector<string> ssplit(const string& s) {
    stringstream ss(s);
    string t;
    vector<string> ans;
    while (ss >> t) ans.push_back(t);
    return ans;
}

template <typename A>
A reversed(const A& a) {
    A b = a;
    reverse(all(b));
    return b;
}

template <typename T>
T closest(const set<T>& S, T key) {
    int ok = 0, ans = -1;

    auto update = [&](int x) {
        if (ok == 0) {
            ok = 1;
            ans = x;
        } else if (abs(x - key) < abs(ans - key)) {
            ans = x;
        }
    };

    auto it = S.lower_bound(key);
    if (it != S.end()) update(*it);
    if (it != S.begin()) update(*(--it));
    return ans;
}
