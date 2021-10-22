
const ll nax = 4e5 + 10;

namespace SA {

ll L[nax][3], tempL[nax][3];
ll P[nax];
ll cnt[nax];  // counts the number of elements in each bucket

void radix(const ll n, const ll ind, ll from[][3], ll to[][3]) {
    const ll buckets = max(n, 256LL) + 2;
    // reset
    rep(i, 0, buckets + 5) cnt[i] = 0;

    // count the number of each element
    rep(i, 0, n) {
        cnt[from[i][ind] + 1]++;  // +1 bc we also have -1
    }

    // finds the cumulative number of elements
    rep(i, 1, buckets) cnt[i] += cnt[i - 1];

    // stable sort
    rrep(i, n - 1, 0) {
        cnt[from[i][ind] + 1]--;
        rep(j, 0, 3) to[cnt[from[i][ind] + 1]][j] = from[i][j];
    }
}

void buildSA(const string& s, ll sa[], ll ind[]) {
    ll n = lg(s);
    ll k = log2(n) + 2;

    rep(i, 0, n) {
        P[i] = s[i];  // initial rank is the character string is
    }

    rep(i, 1, k) {
        rep(j, 0, n) {
            ll nextj = j + tp(i - 1);

            ll first = P[j];
            // empty strings come first in lexicographic order
            ll second = nextj < n ? P[nextj] : -1;

            L[j][0] = first;
            L[j][1] = second;
            L[j][2] = j;
        }

        radix(n, 1, L, tempL);
        radix(n, 0, tempL, L);

        rep(j, 0, n) {
            // If the strings are the same, then your rank is the same as
            // the previous
            P[L[j][2]] =
                j > 0 && L[j - 1][0] == L[j][0] && L[j - 1][1] == L[j][1]
                    ? P[L[j - 1][2]]
                    : j;
        }
    }

    rep(i, 0, n) {
        sa[P[i]] = i;
    }
    rep(i, 0, n) {
        ind[sa[i]] = i;
    }
}

void buildLCP(const string& s, ll sa[], ll ind[], ll lcp[]) {
    // ! assumes sa has already been found

    // kasai's algorithm, find lcp
    // uses the idea that lcp[i+1] will be at least lcp[i] - 1
    ll n = lg(s);

    ll res = 0;
    rep(i, 0, n - 1) {
        ll index = ind[i] - 1;
        if (index < 0) continue;
        ll j = sa[index];

        rep(k, res, n + 5) {
            if (i + k < n && j + k < n && s[i + k] == s[j + k])
                res++;
            else
                break;
        }
        lcp[index] = res;

        if (res) res--;
    }
}
};  // namespace SA