
// system of equations
namespace SOE {
vector<vector<short>> A;  // matrix
vector<short> values;     // rhs
int n, m;

void clear() {
    A.clear();
    values.clear();
    n = 0, m = 0;
}

void add(vector<short>& lhs, short rhs) {
    A.push_back(lhs);
    values.push_back(rhs);
    n++;
    m = lhs.size();
}

void multK(ll ind, ll k) {
    // ind = ind * k
    for (auto& a : A[ind]) {
        a *= k;
        a %= 3;
    }
    values[ind] *= k;
    values[ind] %= 3;
}

void addMultK(ll from, ll to, ll k) {
    // to = to + from * k
    rep(j, 0, m) {
        A[to][j] += A[from][j] * k;
        A[to][j] %= 3;
    }
    values[to] += values[from] * k;
    values[to] %= 3;
}

void swapTwo(ll from, ll to) {
    swap(A[from], A[to]);
    swap(values[from], values[to]);
}

void solve() {
    ll ind = 0;  // row
    rep(j, 0, m) {
        // look for the first row with j'th col non-zero
        ll found = 0;
        rep(ii, ind, n) {
            if (A[ii][j]) {
                swapTwo(ii, ind);
                found = 1;
                break;
            }
        }

        if (!found) continue;

        // use ind
        // divide to get to 1
        multK(ind, invThree(A[ind][j]));

        // for every other row, get it to 0
        rep(otherRow, 0, n) {
            if (otherRow == ind) continue;
            if (A[otherRow][j] == 0) continue;

            addMultK(ind, otherRow, 3 - A[otherRow][j]);
        }

        ind++;
    }
}

}  // namespace SOE
