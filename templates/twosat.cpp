
namespace TwoSAT {
ll ok;
VLL sign, isTrue;

void build(ll n, vector<PLL>& cnf) {
    // input is given as conjunctive normal form
    // e.g. (a or -b) and (b or c)
    // 0..n-1 implies positive, n..2*n-1 implies negative

    sign.assign(n, 0);
    isTrue.clear();
    ok = 1;

    VVLL E(2 * n);
    for (auto& p : cnf) {
        // not a implies b
        E[(p.first + n) % (2 * n)].push_back(p.second);
        // not b implies a
        E[(p.second + n) % (2 * n)].push_back(p.first);
    }

    // find sccs
    Kosaraju::build(2 * n, E);
    VLL ind(2 * n);
    rep(i, 0, Kosaraju::comps.size()) {
        for (auto x : Kosaraju::comps[i]) {
            ind[x] = i;
        }
    }

    rep(i, 0, n) {
        ll pos = ind[i], neg = ind[i + n];
        if (pos == neg) {
            ok = 0;
            return;
        }

        if (pos < neg) {
            // pos implies neg which is a contradiction, therefore must be neg
            sign[i] = -1;
            isTrue.push_back(i + n);
        } else {
            sign[i] = 1;
            isTrue.push_back(i);
        }
    }
}
}  // namespace TwoSAT
