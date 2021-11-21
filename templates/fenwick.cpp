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

    ll sum(ll i) {
        ll total = 0;
        while (i > 0) {
            total += arr[i];
            i -= lsb(i);
        }
        return total;
    }
};
