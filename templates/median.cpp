
struct Median {
    mset<ll> A, B;

    void move(mset<ll>& from, mset<ll>& to, const ll& x) {
        assert(from.find(x) != from.end());
        from.erase(from.find(x));
        to.insert(x);
    }

    void moveBA() {
        assert(sz(B));
        move(B, A, *B.begin());
    }
    void moveAB() {
        assert(sz(A));
        move(A, B, *A.rbegin());
    }

    void balance() {
        while (sz(A) < sz(B)) {
            moveBA();
        }
        while (sz(A) > sz(B) + 1) {
            moveAB();
        }
    }

    void add(ll x) {
        A.insert(x);
        moveAB();
        moveBA();
        balance();
    }

    void remove(ll x) {
        if (A.find(x) != A.end()) {
            A.erase(A.find(x));
        } else if (B.find(x) != B.end()) {
            B.erase(B.find(x));
        } else {
            assert(false);
        }
        balance();
    }

    db query() {
        ll n = sz(A), m = sz(B);
        assert(n + m > 0);

        if (n == m) {
            ll a = *A.rbegin();
            ll b = *B.begin();
            return (a + b) / 2.;
        } else if (n == m + 1) {
            ll a = *A.rbegin();
            return a;
        } else {
            assert(false);
        }
    }
};