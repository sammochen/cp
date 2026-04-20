

namespace Trie {

struct tnode {
    constexpr static NUM_CHILDREN = 26;
    int children[NUM_CHILDREN];
    int ind = -1;

    tnode() {
        rep(i, 0, NUM_CHILDREN) {
            children[i] = -1;
        }
    }
};

tnode nodes[1'000'005];

ll node_index = 0;
int make_tnode() {
    nodes[node_index] = tnode();
    return node_index++;
}

void reset_tnode() {
    node_index = 0;
}

void insert(int root, const string& key) {
    const ll n = key.size();
    int cur = root;

    rep(i, 0, n) {
        int index = key[i] - 'a';
        if (nodes[cur].children[index] == -1) {
            nodes[cur].children[index] = make_tnode();
        }
        cur = nodes[cur].children[index];
    }
    nodes[cur].ind = ind;
}

void check(int root, ll dir, const string& key) {
    const ll n = key.size();
    int cur = root;
    rep(i, 0, n) {
        int index = key[i] - 'a';
        if (nodes[cur].children[index] == -1) {
            // no path
            return;
        }
        cur = nodes[cur].children[index];
    }
    // yes path
}

}  // namespace Trie
