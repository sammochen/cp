
const ll nax = 4e5 + 10;

/**
 * sa is the ORDER if all substrings were sorted
 * ind[i] gives where i is in sa
 * lcp[i] gives the longest common prefix between adj in sa
 *
 * E.g.:
 * s = "banana"
 *
 * Substrings in order are:
 * 0. a
 * 1. ana
 * 2. anana
 * 3. banana
 * 4. na
 * 5. nana
 *
 * sa = [5, 3, 1, 0, 4, 2]
 * ind = [3, 2, 5, 1, 4, 0]
 * lcp = [1, 3, 0, 0, 2]
 */
namespace SA {

ll n, k, maxElement;
ll L[nax][3], tempL[nax][3];
ll P[nax];
ll cnt[nax];  // counts the number of elements in each bucket

void radix(const ll n, const ll ind, ll from[][3], ll to[][3]) {
    const ll buckets = max(n, maxElement) + 2;
    const ll offset = 1;

    // reset
    rep(i, 0, buckets + 5) cnt[i] = 0;

    // count the freq of each element
    rep(i, 0, n) cnt[from[i][ind] + offset]++;

    // cumulative number of elements
    rep(i, 1, buckets) cnt[i] += cnt[i - 1];

    // stable sort
    rrep(i, n - 1, 0) {
        ll val = from[i][ind];
        cnt[val + offset]--;

        rep(j, 0, 3) {
            to[cnt[val + offset]][j] = from[i][j];
        }
    }
}

template <typename A>
void buildSA(const A& s, ll sa[], ll ind[]) {
    n = s.size();
    k = log2(n) + 2;
    maxElement = *max_element(s.begin(), s.end());

    // initial rank is the character string is
    rep(i, 0, n) P[i] = s[i];

    rep(i, 1, k) {
        rep(j, 0, n) {
            const ll j1 = j;
            const ll j2 = j + tp(i - 1);

            ll half1 = P[j1];
            ll half2 = j2 < n ? P[j2] : -1;  // empty strings come first in lexicographic order

            L[j][0] = half1;
            L[j][1] = half2;
            L[j][2] = j;
        }

        radix(n, 1, L, tempL);
        radix(n, 0, tempL, L);

        rep(j, 0, n) {
            if (j > 0 && L[j - 1][0] == L[j][0] && L[j - 1][1] == L[j][1]) {
                // If the val is same as prev val, you have same rank
                P[L[j][2]] = P[L[j - 1][2]];
            } else {
                // Otherwise, new (higher) rank
                P[L[j][2]] = j;
            }
        }
    }

    rep(i, 0, n) {
        sa[P[i]] = i;
        ind[sa[P[i]]] = P[i];
    }
}

template <typename A>
void buildLCP(const A& s, ll sa[], ll ind[], ll lcp[]) {
    // ! assumes sa has already been found

    // kasai's algorithm, find lcp
    // uses the idea that lcp[i+1] will be at least lcp[i] - 1
    ll n = s.size();
    rep(i, 0, n) lcp[i] = 0;

    ll res = 0;
    rep(i, 0, n - 1) {
        ll index = ind[i] - 1;
        if (index < 0) continue;
        ll j = sa[index];

        for (ll k = res; i + k < n && j + k < n; k++) {
            if (s[i + k] == s[j + k]) {
                res++;
            } else {
                break;
            }
        }

        lcp[index] = res;
        if (res) res--;
    }
}
};  // namespace SA