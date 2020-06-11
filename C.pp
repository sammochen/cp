#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define fi first
#define se second
#define pb push_back

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

void in() {}
template <typename A> void in(A & x) { cin >> x; }
template <typename A, typename B> void in(pair<A,B> & x) { in(x.first); in(x.second); }
template <typename A> void in(vector<A> & x) { REP(i,0,(ll)x.size()) in(x[i]); }
template <typename Head, typename... Tail> void in(Head & H, Tail & ... T) {in(H); in(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

const ll inf = (ll)1e18 + 5;

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out bound

ll test = 1;
void solve() {
    ll n, k, ans = inf;
    cin >> n >> k;
    VLL A(n);
    in(A);
    
    map<ll,ll> freq;
    ll big = 0;
    REP(i,0,n) {
        freq[A[i]]++;
        big = max(big, freq[A[i]]);
    }

    if (k <= big) {
        ans = 0;
        printf("Case #%lld: %lld\n", test++, ans);
        return;
    }

    // the slice could be any size - any number divided by 50
    

    if (k == 2) {
        ans = 1;
        printf("Case #%lld: %lld\n", test++, ans);
        return;
    }

    if (k == 3) {
        ans = 2;
        sort(all(A));
        ll smallesttwo = inf;
        REP(i,0,n) {
            if (A[i] % 2 == 0 && freq[A[i]/2]) {
                ans = min(ans, 1LL);
            }
            if (freq[A[i]] == 2) smallesttwo = min(smallesttwo, A[i]);
            if (A[i] > smallesttwo) ans = min(ans, 1LL);
        }
        printf("Case #%lld: %lld\n", test++, ans);
        return;
    }

    
}

signed main() {
	ll t = 1;
	cin >> t;
	REP(i,0,t) solve();
	return 0;
}