
struct XIO {
    static char temp[5'000'005];
    // in
    XIO& operator>>(ll& x) {
        scanf("%lld", &x);
        return *this;
    }
    XIO& operator>>(string& s) {
        scanf("%s", temp);
        s = string(temp);
        return *this;
    }
    XIO& operator>>(char& c) {
        scanf("%c", &c);
        return *this;
    }

    // out
    XIO& operator<<(const ll& x) {
        printf("%lld", x);
        return *this;
    }
    XIO& operator<<(const string& s) {
        printf("%s", s.c_str());
        return *this;
    }
    XIO& operator<<(const char& c) {
        printf("%c", c);
        return *this;
    }
} xio;
