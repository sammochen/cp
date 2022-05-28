#define lsb(i) ((i) & -(i))

struct BIT {
    const ll n;
    VLL arr;
    BIT(ll n) : n(n), arr(n) {}

    void add(ll i, ll k) {
        while (i < n) {
            arr[i] += k;
            i += lsb(i);
        }
    }

    ll sum(ll i) const {
        ll total = 0;
        while (i > 0) {
            total += arr[i];
            i -= lsb(i);
        }
        return total;
    }

    ll sumRange(ll i, ll j) const {
        assert(i <= j);
        return sum(j) - sum(i - 1);
    }
};
