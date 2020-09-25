struct point {
	ll x, y;
};

// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
ll cw(point a, point b, point c) {
	ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	return v == 0 ? 0 : v < 0 ? -1 : 1;
}

bool operator<(const point & a, const point & b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

vector<point> hull(vector<point> & A) {
	ll n = A.size();
	sort(A.begin(), A.end());
	vector<point> H(2*n);

	ll k = 0; // size
	rep(i,0,n) {
		while (k >= 2 && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	ll t = k+1;
	rrep(i,n-2,0) { // takes it all the way to the end
		while (k >= t && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	H.resize(k-1); // discards the last one
	return H;
}