
#define lson (ind << 1)
#define rson (ind << 1 | 1)

struct SegTree {
    static const ll maxn = 1e5 + 5;

    struct node {
        ll l, r;
    };

    node no[maxn * 4];

    void push_up(ll ind) {}
    void push_down(ll ind) {}

    void build(ll l, ll r, ll ind) {
        no[ind].l = l;
        no[ind].r = r;
        if (l == r) {
            // do something
        } else {
            ll mid = (l + r) / 2;
            build(l, mid, lson);
            build(mid + 1, r, rson);
            push_up(ind);
        }
    }

    void update(ll l, ll r, ll ind, ll val) {
        if (l > no[ind].r || r < no[ind].l) return;
        if (l <= no[ind].l && no[ind].r <= r) {
            // do something
        } else {
            push_down(ind);
            update(l, r, lson, val);
            update(l, r, rson, val);
            push_up(ind);
        }
    }

    void query(ll l, ll r, ll ind, ll& ans) {
        if (l > no[ind].r || r < no[ind].l) return;
        if (l <= no[ind].l && no[ind].r <= r) {
            // do something, ans = ?
        } else {
            push_down(ind);
            query(l, r, lson, ans);
            query(l, r, rson, ans);
            push_up(ind);
        }
    }
};
