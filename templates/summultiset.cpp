template <typename T>
struct SumMultiset {
    multiset<T> ms;
    ll sum = 0;

    void insert(const T& x) {
        ms.insert(x);
        sum += x;
    }

    void erase(const T& x) {
        auto it = ms.find(x);
        assert(it != ms.end());
        ms.erase(it);
        sum -= x;
    }

    bool exist(const T& x) const {
        return ms.find(x) != ms.end();
    }
    int size() const {
        return ms.size();
    }
    T lo() const {
        return *ms.begin();
    }
    T hi() const {
        return *ms.rbegin();
    }
};
