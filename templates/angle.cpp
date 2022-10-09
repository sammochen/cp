
const double PI = atan(1) * 4;

struct Angle {
    ll x, y;  // x, y of the coordinate
    ll revs;  // revolutions, the 0-indexed circle its on

    Angle(ll x, ll y, ll r = 0) {
        ll g = gcd(x, y);
        assert(g > 0);

        this->x = x / g;
        this->y = y / g;
        this->revs = r;
    }

    ll quadrant() const {
        // * NOTE this is 0-indexed
        if (y >= 0 && x > 0) return 0 + revs * 4;
        if (x <= 0 && y > 0) return 1 + revs * 4;
        if (y <= 0 && x < 0) return 2 + revs * 4;
        if (x >= 0 && y < 0) return 3 + revs * 4;
        assert(false);
    }

    PLL bound(ll quad) const {
        // given the quad, return the [lo, hi) bound the angle should be in
        return {quad * 90, (quad + 1) * 90};
    }

    double angle() const {
        // Return an angle from [0, 360)
        PLL b = bound(quadrant());

        double theta = x == 0 ? 90 : atan(y / (double)x) / PI * 180;
        theta += revs * 360;  // roughly get to the right angle

        // adjust
        while (theta < b.first) theta += 180;
        while (theta >= b.second) theta -= 180;
        assert(theta >= b.first && theta < b.second);
        return theta;
    }

    ll compare(const Angle& rhs) const {
        // return -1 if self is smaller, 0 if same, 1 if self is bigger
        if (x == rhs.x && y == rhs.y && revs == rhs.revs) return 0;
        ll q = quadrant(), rhsq = rhs.quadrant();
        if (q < rhsq) return -1;
        if (q > rhsq) return 1;

        // same quadrant
        if (y * rhs.x < x * rhs.y) return -1;
        return 1;
    }
};

ostream& operator<<(ostream& os, const Angle& angle) {
    os << "{" << angle.x << ", " << angle.y << "}";
    return os;
}
