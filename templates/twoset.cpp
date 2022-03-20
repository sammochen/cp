template <typename T>
struct TwoSet {
    multiset<T> A, B;  // A is low, B is high

    template <typename It>
    void moveIt(multiset<T>& from, multiset<T>& to, It x) {
        from.erase(x);
        to.insert(*x);
    }

    void moveBA() {
        assert(B.size());
        moveIt(B, A, B.begin());
    }
    void moveAB() {
        assert(A.size());
        moveIt(A, B, --A.end());
    }

    void balance() {
        // impl
    }

    void add(const T& t) {
        A.insert(t);
        moveAB();
        moveBA();
        balance();
    }

    void remove(const T& x) {
        if (A.find(x) != A.end()) {
            A.erase(A.find(x));
        } else if (B.find(x) != B.end()) {
            B.erase(B.find(x));
        } else {
            assert(false);
        }
        balance();
    }

    T query() {
        // impl
    }
};
