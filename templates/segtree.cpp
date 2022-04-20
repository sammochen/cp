
#define lson (ind << 1)
#define rson (ind << 1 | 1)

namespace SegTree {
const ll N = 100'005;
struct node {
    ll l, r;  // [l, r] bounds for the node, inclusive
};
node nodes[N * 4];

void push_up(ll ind) {}
void push_down(ll ind) {}

void build(ll l, ll r, ll ind) {
    nodes[ind].l = l;
    nodes[ind].r = r;
    if (l == r) {
        // TODO: leaf node - assign value
    } else {
        // parent node - the values will be pushed up from the children
        ll mid = (l + r) / 2;
        build(l, mid, lson);
        build(mid + 1, r, rson);
        push_up(ind);
    }
}

void update(ll l, ll r, ll ind, ll val) {
    if (l > nodes[ind].r || r < nodes[ind].l) return;
    if (l <= nodes[ind].l && nodes[ind].r <= r) {
        // TODO: lazily save some state. note the state will be pushed down later
    } else {
        push_down(ind);
        update(l, r, lson, val);
        update(l, r, rson, val);
        push_up(ind);
    }
}

void query(ll l, ll r, ll ind, ll& ans) {
    if (l > nodes[ind].r || r < nodes[ind].l) return;
    if (l <= nodes[ind].l && nodes[ind].r <= r) {
        // TODO: do something. ans = ?
    } else {
        push_down(ind);
        query(l, r, lson, ans);
        query(l, r, rson, ans);
        push_up(ind);
    }
}
}  // namespace SegTree
