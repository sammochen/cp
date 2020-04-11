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

void walk(Node * & activeNode, ll & activeEdge, ll & activeLength, string & s) {
    while (activeLength && activeNode->edges[s[activeEdge]]->length() <= activeLength) {
        ll edgeLength = activeNode->edges[s[activeEdge]]->length();
        if (edgeLength <= activeLength) {
            activeNode = activeNode->edges[s[activeEdge]]->node;
            activeLength -= edgeLength;
            activeEdge += edgeLength;
        }
    }
}

Node* build(string s) {
    ll n = s.length();
    Node* root = new Node(); // this is my root

    ll remaining = 0;
    Node* activeNode = root;
    ll activeEdge = -1;
    ll activeLength = 0;
    ll end = -1;

    // insert each one one by one
    REP(i,0,n) {
        remaining++;
        end++;

        Node * prev = NULL;

        while (remaining > 0) {
            // we are already somewhere
            if (walk(activeNode, activeEdge, activeLength, s), activeLength > 0) {
                if (activeNode->edges[s[activeEdge]]->get(activeLength, s) == s[i]) {
                    activeLength++;
                    break;
                    // showstopper
                } else {
                    // we have to make a new internal node
                    Edge * curEdge = activeNode->edges[s[activeEdge]];
                    Node * midNode;
                    debug(i, activeLength);
                   
                    // new middle node
                    midNode = curEdge->split(activeLength, s);
                    midNode->next = root;
                    if (prev) prev->next = midNode;
                    prev = midNode;
                    
                    midNode->edges[s[i]] = new Edge(NULL, i, -1);
                    remaining--;
                   
                    // i should change activeNode to its parent, 
                    if (activeNode == root) {
                        activeEdge++;
                        activeLength--;
                    } else {
                        activeNode = activeNode->next;
                    }
                }
            } else {
                if (activeNode->edges[s[i]]) {
                    activeEdge = i;
                    activeLength = 1;
                    break;
                    // showstopper!
                } else {
                    // otherwise, make new edge with node
                    activeNode->edges[s[i]] = new Edge(NULL, i, -1);
                    remaining--;
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
        t += string(tab, ' ') + "(" + to_string(edge.first) + ", " + to_string(edge.second) + ")" + "\n";

        if (edge.second->node) {
            t += to_string(edge.second->node, tab+2);
        }
    }
    return t;
}

string to_string(Node * root) {
    return to_string(root, 0);
}

void solve() {
    cin >> s;

    Node * root = build(s);
    //debug(root);
    cout << to_string(root) << endl;
    
    
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}