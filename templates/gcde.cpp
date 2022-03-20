// Function for extended Euclidean Algorithm
struct gcd_result {
    ll g, x, y;
};

// Solves the problem: ax + by = gcd(a, b)
gcd_result gcde(ll a, ll b) {
    // Base Case - if a = 0, gcd = b.
    // 0 * 0 + b * 1 = b
    if (a == 0) return {b, 0, 1};

    const auto [gcd, next_x, next_y] = gcde(b % a, a);
    ll x = next_y - (b / a) * next_x;
    ll y = next_x;
    return {gcd, x, y};
}
