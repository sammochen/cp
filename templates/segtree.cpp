struct SegTree{
    static const int maxn = ;

    struct node{
        int l,r;
    };

    node no[maxn*4];
    void push_up(int ind){

    }
    void push_down(int ind){
    }
    void build(int l,int r,int ind){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){

        }else{
            int mid = (l+r)/2;
            build(l,mid,lson);
            build(mid+1,r,rson);
            push_up(ind);
        }
    }
    void update(int l,int r,int ind,int val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(int l,int r,int ind,int& ans){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            
        }else{
            push_down(ind);
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);

        }
    }
};

