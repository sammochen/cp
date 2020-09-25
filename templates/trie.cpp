struct tnode {
	tnode* children[26];
	int endofword;
};

void insert(tnode *root, string key) { 
    tnode *cur = root; 
    rep(i,0,key.length()) {
        ll index = key[i] - 'A'; 
        if (!cur->children[index]) {
			cur->children[index] = new tnode(); 
		}
        cur = cur->children[index]; 
    } 
  
    // mark last node as leaf 
    cur->endofword = 1; 
}

