struct tnode {
    vector<tnode *> children;
    int isEnd = 0;

    tnode() {
        children.resize(26);
        isEnd = 0;
    }
};

void insert(tnode *root, const string &key) {
    tnode *cur = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'A';
        if (!cur->children[index]) {
            cur->children[index] = new tnode();
        }
        cur = cur->children[index];
    }

    // mark last node as leaf
    cur->isEnd = 1;
}
