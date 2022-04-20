struct AhoCorasick {
    struct T {
        T* child[26];
        VLL ind;
        T* failure;
    };

    T* root;
    void build(VS& dictionary, VLL& B) {
        root = new T();
        root->failure = root;
        rep(i, 0, sz(dictionary)) {
            string& d = dictionary[i];
            T* cur = root;
            fe(c, d) {
                T*& next = cur->child[c - 'a'];
                if (!next) next = new T();
                cur = next;
            }
            cur->ind.pb(i);
        }

        queue<T*> Q;
        rep(i, 0, 26) {
            if (root->child[i]) {
                root->child[i]->failure = root;
                Q.push(root->child[i]);
            }
        }
        while (sz(Q)) {
            T* at = Q.front();
            Q.pop();

            rep(i, 0, 26) {
                if (at->child[i]) {
                    // look at failure state of current state, and update
                    T* failure = at->failure;
                    while (!failure->child[i]) {
                        failure = failure->failure;
                        if (failure == root) break;
                    }
                    if (failure->child[i]) failure = failure->child[i];

                    at->child[i]->failure = failure;

                    Q.push(at->child[i]);
                }
            }
        }
    }

    ll search(string& s, ll x, ll y, VLL& B) {
        ll ans = 0;
        T* cur = root;
        fe(c, s) {
            while (!cur->child[c - 'a']) {
                cur = cur->failure;
                if (cur == root) break;
            }
            if (cur->child[c - 'a']) cur = cur->child[c - 'a'];

            // while cur is not root, keep failing it
            T* t = cur;
            while (t != root) {
                fe(ind, t->ind) {
                    if (x <= ind && ind <= y) ans += B[ind];
                }
                t = t->failure;
            }
        }
        return ans;
    }
};