
namespace CHT {
// Works for increasing or decreasing gradients
struct Line {
    // y = mx + c
    ll m, c;

    db intersect(const Line& line) const {
        db dc = line.c - c;
        db dm = m - line.m;
        assert(dm != 0);
        return dc / dm;
    }

    ll at(ll x) const {
        return m * x + c;
    }
};

vector<db> X;  // intersections
vector<Line> lines;

void init(const Line& line) {
    // first line^
    X = {-1e18};
    lines = {line};
}

void add(const Line& line) {
    // assumes the gradients are in sorted order
    while (lines.size() >= 2 && line.intersect(lines[lines.size() - 2]) <= X.back()) {
        X.pop_back();
        lines.pop_back();
    }

    X.push_back(lines.back().intersect(line));
    lines.push_back(line);
}

ll query(ll x) {
    auto ind = upper_bound(all(X), x) - X.begin() - 1;  // -1 bc there is extra X
    auto& line = lines[ind];
    return lines[ind].at(x);
}

}  // namespace CHT
