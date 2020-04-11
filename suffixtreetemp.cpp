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

struct SuffixTreeNode;
struct SuffixTreeEdge;
typedef SuffixTreeNode Node;
typedef SuffixTreeEdge Edge;


void bye(string s) {
    debug("bad!", s);
    exit(0);
}
struct SuffixTreeNode {
    map<char,Edge*> edges;
    Node* next;
    SuffixTreeNode() {
       
    }
};
struct SuffixTreeEdge {
    SuffixTreeNode* node;
    ll i, j = -1;
    SuffixTreeEdge(Node* a, ll b, ll c) {
        node = a;
        i = b;
        j = c;
    }

    char get(ll ind, string & s) {
        return s[ind+i];
    }

    ll length() {
        if (j == -1) return inf;
        return j-i+1;
    }
    
    // ind is where the new one starts
    Node* split(ll ind, string & s) {
        SuffixTreeNode* midNode = new SuffixTreeNode();
        Edge* midEdge = new Edge(node, i+ind, j); // point to old node

        node = midNode;
        i = i;
        j = i+ind - 1;

        midNode->edges[s[i+ind]] = midEdge;
        return midNode;
    }
};

void walk(Node * & node, ll & edge, ll & len, string & s) {
    while (len > 0 && node->edges[s[edge]]->length() <= len) {
        ll edgeLength = node->edges[s[edge]]->length();
        
        node = node->edges[s[edge]]->node;
        len -= edgeLength;
        edge += edgeLength;
    }
}

Node* build(string s) {
    ll n = s.length();
    Node* root = new Node(); // this is my root

    ll remaining = 0; // remaining is how many letters there are yet to do
    Node* node = root; // current active node
    ll edge = -1; // current active edge
    ll len = 0; // current len down the active edge
    ll end = -1; // end value

    // insert each one one by one
    REP(i,0,n) {
        remaining++;
        end++;

        Node * prev = NULL;

        while (remaining > 0) {
            if (walk(node, edge, len, s), len > 0) {
                debug(i, remaining, s[edge], len, "\n", node);
				// if we are walking somewhere, and len > 0 (if len == 0, we are on some node and we skip)
                if (node->edges[s[edge]]->get(len, s) == s[i]) {
					// this is the case that the next letter is the same. we move the len pointer up.
					// this is a showstopper case
                    len++;
                    break;
                } else {
					// if it does not match, we have to split the node.
                    // we have to make a new internal node
                    Node * midNode = node->edges[s[edge]]->split(len, s);
                    
                    midNode->next = root;
                    if (prev) prev->next = midNode;
                    prev = midNode;
                    
					// this is making the new edge for the new node to where we are.
					// this is a leaf node, so we decrement remaining 
                    midNode->edges[s[i]] = new Edge(NULL, i, -1);
                    remaining--;

				   	// now we go "back". 
					// if the active node is the root, we increase one to edge and decrease len.
					// if the active node is not the root, we go to its next root
                    if (node == root) {
                        edge++;
                        len--;
                    } else {
                        node = node->next;
                        if (node == root) {
                            edge++;
                            remaining = len-1;
                        }
                    }
                }
            } else {
				// else, we are at some existing node already.
                if (node->edges[s[i]]) {
					// if the edge exists, we move in that direction
                    edge = i;
                    len = 1;
                    break;
                } else {
                    // otherwise, make new edge with node
                    node->edges[s[i]] = new Edge(NULL, i, -1);
                    remaining--;
					if (node != root) {
                        node = node->next;
                    }
                }
            }
            
        }
    }
    return root;
}

string s;

string to_string(Edge * edge) {
    ll last = edge->j;
    if (last == -1) last = s.length()-1;

    string t = s.substr(edge->i, last-edge->i + 1);
    return t;
}

string to_string(Node * node, ll tab) {
    string t;
    for (pair<char,Edge*> edge : node->edges) {
        t += string(tab, ' ') + "(" + to_string(edge.second) + ")" + "\n";

        if (edge.second->node) {
            t += to_string(edge.second->node, tab+2);
        }
    }
    return t;
}

string to_string(Node * root) {
    return to_string(root, 0);
}

ll size(Node * node, ll n) {
	if (!node) return 0;
	ll ans = 0;
	for (pair<char,Edge*> edge : node->edges) {
		if (edge.second->j == -1) {
			ans += n - edge.second->i;
		} else {
			ans += edge.second->length();
		}
		ans += size(edge.second->node, n);
	}
	return ans;
}

void solve() {
    cin >> s;
	ll n = s.length();
	s += "$";	

    Node * root = build(s);
    debug("\n",root);
	cout << size(root, n) << endl;


    
    
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}