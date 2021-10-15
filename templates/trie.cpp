struct tnode {
    tnode *children[26];
    int isEnd = 0;
};

void insert(tnode *root, const string &key) {
    tnode *cur = root;
    rep(i, 0, lg(key)) {
        ll index = key[i] - 'A';
        if (!cur->children[index]) {
            cur->children[index] = new tnode();
        }
        cur = cur->children[index];
    }

    // mark last node as leaf
    cur->isEnd = 1;
}
