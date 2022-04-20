
namespace Inv {
ll count(ll i, ll j, VLL& temp) {
    if (i >= j) return 0;
    ll mid = (i + j) / 2;
    const ll L = count(i, mid, temp);      // L sub problem
    const ll R = count(mid + 1, j, temp);  // R sub problem

    VLL ans = {};
    ll a = i, b = mid + 1, cur = 0;

    while (a < mid + 1 || b < j + 1) {
        // Whenever we choose right, we invert against all remaining lefts.
        const ll x = a == mid + 1 ? inf : temp[a];
        const ll y = b == j + 1 ? inf : temp[b];
        const ll chooseLeft = min(x, y) == x;

        if (chooseLeft) {
            ans.push_back(temp[a++]);
        } else {
            ans.push_back(temp[b++]);
            cur += mid + 1 - a;
        }
    }

    rep(x, i, j + 1) temp[x] = ans[x - i];  // update (and sort) temp[i:j+1]
    return L + R + cur;
}

ll count(const VLL& arr) {
    VLL temp = arr;
    return count(0, arr.size() - 1, temp);
}
}  // namespace Inv
