#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
