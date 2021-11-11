#include <bits/stdc++.h>
using namespace std;

// Don't forget!!
// * int overflow
// * memoize

typedef long long ll;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll, ll> PLL;

#define rep(x, l, u) for (ll x = l; x < u; x++)
#define rrep(x, l, u) for (ll x = l; x >= u; x--)

const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e18 + 5;

// * round up
ll rup(ll a, ll b) {
    return a % b ? a / b + 1 : a / b;
}

// * is vowel
ll isvowel(char c) {
    return string("aeiou").find(c) != string::npos;
}

// * edge list to adj list
vector<vector<int>> toE(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> E(n);
    for (auto& e : edges) {
        E[e[0]].push_back(e[1]);
        E[e[1]].push_back(e[0]);
    }
    return E;
}