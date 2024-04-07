
struct tnode {
    vector<unique_ptr<tnode>> children;
    set<PLL> inds;

    tnode() {
        children.resize(26);
    }
};

void insert(tnode* root, const string& key, ll ind) {
    PLL p = {(ll)key.size(), ind};

    tnode* cur = root;
    cur->inds.insert(p);
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (!cur->children[index]) {
            cur->children[index] = make_unique<tnode>();
        }
        cur = cur->children[index].get();
        cur->inds.insert(p);
    }
}

ll query(tnode* root, const string& key) {
    tnode* cur = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (!cur->children[index]) {
            return cur->inds.begin()->second;
        }
        cur = cur->children[index].get();
    }
    return cur->inds.begin()->second;
}
