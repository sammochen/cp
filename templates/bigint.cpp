// TODO incomplete
class BigInt {
   public:
    BigInt() : A({}) {}
    BigInt(ll x) A({x}) {}
    BigInt(string s) {
        while (s.length() > 0) {
            ll take = min(k, (ll)s.length());

            A.push_back(stoll(s.substr(s.length() - take)));
            s = s.substr(0, s.length() - take);
        }
    }

    BigInt operator+(ll x) const {}

    BigInt operator+(const BigInt& other) const {}

   private:
    const ll k = 15;
    const ll base = 1000 * 1000 * 1000 * 1000 * 1000;  // 1e15

    VLL A;
    ll sign;
};