
struct tnode {
    vector<unique_ptr<tnode>> children;
    tnode() {
        children.resize(26);
    }
};

void insert(tnode* root, const string& key) {
    tnode* cur = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if (!cur->children[index]) {
            cur->children[index] = make_unique<tnode>();
        }
        cur = cur->children[index].get();
    }
}
