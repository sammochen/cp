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

struct trienode {
	struct trienode *children[26];
	int endofword;
	int count = 0;
	int len = 0;
	int minus = 0;
	trienode *parent;
};


vector<trienode*> nodes;

trienode *getNode(void) {
	trienode *pnode = new trienode;
	pnode->endofword = 0;
	for (int i = 0; i < 26; i++) {
		pnode->children[i] = NULL;
	}
	nodes.push_back(pnode);
	return pnode;
}

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(trienode *root, string key) { 
    trienode *crawl = root; 
    for (int i = 0; i < key.length(); i++) { 
        int index = key[i] - 'A'; 
        if (!crawl->children[index]) {
			crawl->children[index] = getNode(); 
			crawl->children[index]->len = crawl->len + 1;
			crawl->children[index]->parent = crawl;
		}
        crawl = crawl->children[index]; 
		crawl->count++;
    } 
  
    // mark last node as leaf 
    crawl->endofword = 1; 
}

bool comp(trienode* a, trienode* b) {
	return a->len < b->len;
}

ll test = 1;

void solve() {
	nodes.clear();
	ll n, k;
	cin >> n >> k;
	vector<string> A(n);
	REP(i,0,n) {
		cin >> A[i];
	}

	trienode *root = getNode();
	REP(i,0,n) {
		insert(root, A[i]);
	}

	sort(nodes.rbegin(), nodes.rend(), comp);

	ll ans = 0;
	for (trienode* node : nodes) {
		if (node->len == 0) continue;

		// carry the minus forward
		node->count -= node->minus;
		node->parent->minus += node->minus;
		node->minus = 0;

		ll amount = node->count / k;
		ans += node->len * amount;
		node->count %= k;
		node->parent->minus += k * amount;
	}

	printf("Case #%lld: %lld\n", test++, ans);

}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}