struct point {
    double x, y;
};

struct circle {
    point p;
    double r;
};

// https://www.geeksforgeeks.org/minimum-enclosing-circle-set-2-welzls-algorithm/
// Helper method to get a circle defined by 3 points
point get_circle_center(double bx, double by, double cx, double cy) {
    double B = bx * bx + by * by;
    double C = cx * cx + cy * cy;
    double D = bx * cy - by * cx;
    return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
}

// Function to return a unique circle that
// intersects three points
point circle_from(const point& A, const point& B, const point& C) {
    point I = get_circle_center(B.x - A.x, B.y - A.y, C.x - A.x, C.y - A.y);

    I.x += A.x;
    I.y += A.y;
    return I;
}

double sed(vector<point> A) {
    point c = A[0];
    double r = 0;
    ll n = sz(A);
    rep(i, 1, n) {
        // if the point doesnt fit in the existing circle
        if (dist(A[i], c) >= r + eps) {
            // change the center to itself
            c = A[i], r = 0;

            // for every point that was previously visited
            rep(j, 0, i) {
                if (dist(A[j], c) >= r + eps) {
                    c.x = (A[i].x + A[j].x) / 2.;
                    c.y = (A[i].y + A[j].y) / 2.;
                    r = dist(c, A[i]);

                    rep(k, 0, j) {
                        if (dist(A[k], c) >= r + eps) {
                            c = circle_from(A[i], A[j], A[k]);
                            r = dist(c, A[i]);
                        }
                    }
                }
            }
        }
    }
    return r;
}
