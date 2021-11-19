// Counts num inversions of an array using merge sort
// O(nlogn)
namespace Inv {
VLL A;

ll helper(ll i, ll j) {
    if (j - i <= 0) return 0;

    ll mid = (i + j) / 2;
    const auto L = helper(i, mid);      // left side
    const auto R = helper(mid + 1, j);  // right side

    VLL ans = {};
    ll a = i, b = mid + 1, cur = 0;

    while (a < mid + 1 || b < j + 1) {
        bool chooseRight = false;

        if (a == mid + 1) {
            chooseRight = true;
        } else if (b == j + 1) {
            chooseRight = false;
        } else {
            ll ele = min(A[a], A[b]);
            chooseRight = ele == A[a] ? false : true;
        }

        if (chooseRight == false) {
            ans.push_back(A[a++]);
        } else {
            ans.push_back(A[b++]);

            // if i choose right, i am inverting against all remaining Ls
            cur += mid + 1 - a;
        }
    }
    for (int x = i; x <= j; x++) {
        A[x] = ans[x - i];
    }

    return L + R + cur;
}

ll count(const VLL& arr) {
    A = arr;
    return helper(0, arr.size() - 1);
}
}  // namespace Inv
