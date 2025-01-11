

#define lson (ind << 1)
#define rson (ind << 1 | 1)

namespace SegTree {
const ll N = 100'005;
struct node {
    ll l, r;   // [l, r] bounds for the node, inclusive
    VLL best;  // 1 if you need left/right, 0 is any
};
node nodes[N * 4];

void push_up(ll ind) {
    // need both
    nodes[ind].best[3] = nodes[lson].best[3] + nodes[rson].best[3];

    // i = 1 is need left
    nodes[ind].best[1] = max(nodes[lson].best[1], nodes[lson].best[3] + nodes[rson].best[1]);

    // i = 2 is need right
    nodes[ind].best[2] = max(nodes[rson].best[2], nodes[rson].best[3] + nodes[lson].best[2]);

    // i = 0 is do not need anything
    nodes[ind].best[0] = -inf;
    upmax(nodes[ind].best[0], nodes[lson].best[0]);
    upmax(nodes[ind].best[0], nodes[rson].best[0]);
    upmax(nodes[ind].best[0], nodes[lson].best[2] + nodes[rson].best[1]);
}

void push_down(ll ind) {}

void build(ll l, ll r, ll ind, vector<int>& A) {
    nodes[ind].l = l;
    nodes[ind].r = r;
    nodes[ind].best.assign(4, -inf);
    if (l == r) {
        // TODO: leaf node - assign value
        nodes[ind].best.assign(4, A[l]);
    } else {
        // parent node - the values will be pushed up from the children
        ll mid = (l + r) / 2;
        build(l, mid, lson, A);
        build(mid + 1, r, rson, A);
        push_up(ind);
    }
}

void update(ll l, ll r, ll ind, ll val) {
    if (l > nodes[ind].r || r < nodes[ind].l) return;
    if (l <= nodes[ind].l && nodes[ind].r <= r) {
        // TODO: lazily save some state. note the state will be pushed down later
        assert(l == r);
        nodes[ind].best = VLL(4, val);
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
        upmax(ans, nodes[ind].best[0]);
    } else {
        push_down(ind);
        query(l, r, lson, ans);
        query(l, r, rson, ans);
        push_up(ind);
    }
}

ll query(ll l, ll r) {
    ll ans = -inf;
    query(l, r, 1, ans);
    return ans;
}
}  // namespace SegTree
