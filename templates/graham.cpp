#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

struct point {
	ll x, y;
};

// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
ll cw(point a, point b, point c) {
	ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	return v == 0 ? 0 : v < 0 ? -1 : 1;
}

ll dist(const point & a, const point & b) {
	ll dy = b.y - a.y, dx = b.x - a.x;
	return dy*dy + dx*dx;
}

point first;
// not allowed to compare with itself!!!
bool compare(const point & a, const point & b) {
	ll v = cw(first, a, b);
	return v == 0 ? dist(first,a) < dist(first,b) : v < 0;
}

point nexttop(stack<point> & S) {
	point t = S.top();
	S.pop();
	point nt = S.top();
	S.push(t);
	return nt;
}

vector<point> hull(vector<point> & A) {
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

	vector<point> B; // all the points that are not 'first'
	first = {x0, y0};
	REP(i,0,A.size()) {
		if (A[i].x != first.x || A[i].y != first.y) B.push_back(A[i]);
	}
	sort(B.begin(), B.end(), compare);

	stack<point> S;

	S.push(first);
	S.push(B[0]);
	S.push(B[1]);

	REP(i,2,B.size()) {
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
void solve() {

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}