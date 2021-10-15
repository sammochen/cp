
const ll nax = 4e5 + 5;
ll P[nax];
ll L[nax][2][3];
ll sa[nax];
ll lcp[nax];

template <typename A>
void arrdebug(A a[], ll n) {
    rep(i, 0, n) {
        fout(a[i], ' ');
    }
    fout(nl);
}

void radixsort(ll ind, ll n, ll bucket, ll from, ll to) {
    VLL cnt(bucket);
    rep(i, 0, n) {
        cnt[L[i][from][ind] + 1]++;
    }

    rep(i, 1, bucket) cnt[i] += cnt[i - 1];

    rrep(i, n - 1, 0) {
        --cnt[L[i][from][ind] + 1];

        rep(j, 0, 3) {
            L[cnt[L[i][from][ind] + 1]][to][j] = L[i][from][j];
        }
    }
}

void suffixarray(string& s) {
    ll n = lg(s);
    ll k = log2(n) + 2;

    rep(i, 0, n) {
        P[i] = s[i];  // get initial rank
    }

    rep(i, 1, k) {
        rep(j, 0, n) {
            L[j][0][0] = P[j];
            L[j][0][1] = j + tp(i - 1) < n ? P[j + tp(i - 1)] : -1;
            L[j][0][2] = j;
        }

        ll buckets = n + 1;
        if (i == 1) upmax(buckets, 256);
        radixsort(1, n, buckets, 0, 1);
        radixsort(0, n, buckets, 1, 0);

        rep(j, 0, n) {
            P[L[j][0][2]] = j && L[j - 1][0][0] == L[j][0][0] &&
                                    L[j - 1][0][1] == L[j][0][1]
                                ? P[L[j - 1][0][2]]
                                : j;
        }
    }

    rep(i, 0, n) {
        sa[P[i]] = i;
    }

    VLL ind(n);
    rep(i, 0, n) {
        ind[sa[i]] = i;
    }

    ll res = 0;
    rep(i, 0, n - 1) {
        ll index = ind[i] - 1;
        if (index < 0) continue;
        ll j = sa[index];

        rep(k, res, nax) {
            if (s[i + k] == s[j + k])
                res++;
            else
                break;
        }
        lcp[index] = res;

        if (res) res--;
    }
}