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

struct Node {
	Node *left, *right;
	ll val;
};

Node* build(ll ind, VLL & A) {
	if (ind >= A.size()) return NULL;

	Node * node = new Node();
	node->val = A[ind];
	node->left = build(ind * 2, A);
	node->right = build(ind * 2 + 1, A);
	return node;
}

ll inv = -1;
ll maxlayers = 3;
void draw(Node * node, ll layer, VVLL & layers) {
	if (layer == maxlayers) return;
	if (node) {
		layers[layer].push_back(node->val);
		draw(node->left, layer+1, layers);
		draw(node->right, layer+1, layers);
	} else {
		layers[layer].push_back(inv);
		draw(NULL, layer+1, layers);
		draw(NULL, layer+1, layers);
	}

}
string to_string(Node * node) {
	VVLL layers(maxlayers);
	draw(node, 0, layers);
	return to_string(layers);
}

void solve() {
	ll n, m;
	cin >> n >> m;
	VLL A(1<<n);
	REP(i,0,(1<<n)-1) {
		cin >> A[i+1];
	}

	Node *node = build(1, A);
	debug(node);


}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}