
namespace PseudoForest {
ll n;
VLL child;

vector<uset<ll>> circles;  // vector of unique circles
VLL distToCircle;          // distToCircle[i] is the dist to some circle, 0 if in circle.
VLL firstCircle;           // firstCircle[i] is the first circle node i sees.
VLL circleId;              // circleId[i] is the circle id this node will eventually go to.
ll curId;                  // next circle id
VLL onStack;               // onStack[i] is 1 if i is on the dfs stack

void reset() {
    circles.assign(n, {});
    distToCircle.assign(n, -1);
    firstCircle.assign(n, -1);
    circleId.assign(n, -1);
    onStack.assign(n, 0);
    curId = 0;
}

// Return "hit point", circleId
PLL dfs(ll at) {
    // If 'at' was calculated on some previous dfs
    if (circleId[at] != -1) return {-1, circleId[at]};

    // If this is not pre-seen and you are hitting yourself, you have found a loop
    if (onStack[at]) return {at, curId++};

    onStack[at] = 1;
    PLL ans = dfs(child[at]);
    onStack[at] = 0;

    circleId[at] = ans.second;
    if (ans.first != -1) {  // still in loop
        circles[ans.second].insert(at);
        distToCircle[at] = 0;
        firstCircle[at] = at;
    } else {  // not in loop
        distToCircle[at] = distToCircle[child[at]] + 1;
        firstCircle[at] = firstCircle[child[at]];
    }

    // If we are at the "hit point", unset the hit point to indicate we are not in the loop anymore
    if (at == ans.first) ans.first = -1;
    return ans;
}

void solve(const VLL& tempChild) {
    child = tempChild;
    n = tempChild.size();

    reset();
    rep(i, 0, n) dfs(i);
}
}  // namespace PseudoForest
