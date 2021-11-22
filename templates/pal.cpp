using ll = long long;
using VLL = vector<ll>;

struct Pal {
    // "val + mid + lav"

    const ll base;
    Pal(ll base) : base(base) {}

    struct iterator {
        const ll base;
        ll val, mid;
        iterator(ll base, ll val, ll mid) : base(base), val(val), mid(mid) {}

        ll operator*() {
            ll ans = val;
            if (mid != -1) {  // add mid
                ans *= base;
                ans += mid;
            }
            ll valCopy = val;
            while (valCopy) {  // add reverse
                ans *= base;
                ans += valCopy % base;
                valCopy /= base;
            }
            return ans;
        }

        void operator++() {
            if (mid == -1) {
                val++;
                if (isFullPow(val)) {
                    mid = 0;
                    val = val / base;
                }
            } else {
                mid++;
                if (mid == base) {
                    val++;
                    if (isFullPow(val)) {
                        mid = -1;
                    } else {
                        mid = 0;
                    }
                }
            }
        }

        void operator++(int) {
            this->operator++();
        }

        bool operator!=(const iterator& it) {
            return val != it.val || mid != it.mid;
        }

       private:
        bool isFullPow(ll x) {
            while (x % base == 0) x /= base;
            return x == 1;
        }
    };

    iterator begin() {
        return iterator(base, 0, 1);
    }
    iterator end() {
        return iterator(base, -1, -1);
    }
};
