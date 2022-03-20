struct point {
    ll x, y;
};

// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
ll cw(point a, point b, point c) {
    ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    return v == 0 ? 0 : v < 0 ? -1 : 1;
}

// return square of dist
ll dist(const point& a, const point& b) {
    ll dy = b.y - a.y, dx = b.x - a.x;
    return dy * dy + dx * dx;
}

point first;
// not allowed to compare with itself!!!
bool compare(const point& a, const point& b) {
    ll v = cw(first, a, b);
    return v == 0 ? dist(first, a) < dist(first, b) : v < 0;
}

point nexttop(stack<point>& S) {
    point t = S.top();
    S.pop();
    point nt = S.top();
    S.push(t);
    return nt;
}

vector<point> hull(vector<point>& A) {
    ll n = A.size();
    ll x0 = inf, y0 = inf;

    // find bottomest point, and left if tie on y
    for (point p : A) {
        if (p.y < y0) {
            y0 = p.y;
            x0 = p.x;
        } else if (p.y == y0) {
            x0 = min(x0, p.x);
        }
    }

    vector<point> B;  // all the points that are not 'first'
    first = {x0, y0};
    REP(i, 0, A.size()) {
        if (A[i].x != first.x || A[i].y != first.y) B.push_back(A[i]);
    }
    sort(B.begin(), B.end(), compare);

    stack<point> S;

    S.push(first);
    S.push(B[0]);
    S.push(B[1]);

    REP(i, 2, B.size()) {
        while (cw(nexttop(S), S.top(), B[i]) == 1) {
            S.pop();
        }
        S.push(B[i]);
    }

    // right now stack has it in reverse order

    vector<point> ans;
    while (S.size()) {
        ans.push_back(S.top());
        S.pop();
    }
    return ans;
}
