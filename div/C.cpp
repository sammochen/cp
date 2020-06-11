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
const ll mod = 1e9+7;

vector<vector<string>> words(4, vector<string>(4));
vector<vector<string>> hints;
map<string,ll> x, y;

char other(char c) {
    if (c == 'R') return 'B';
    return 'R';
}

map<vector<string>, map<char,ll>> dp;

ll win(vector<string> state, char player, ll blues, ll reds) {
    if (dp[state][player]) return dp[state][player] - 1;

    ll best = 0;
    for (vector<string> hint : hints) {
        vector<string> next = state;
        ll nextblues = blues;
        ll nextreds = reds;
        ll ok = 0; // you need to make a move
        
        for (string clue : hint) {
            char cur = next[x[clue]][y[clue]];
            if (cur == 'U') continue;

            ok = 1;
            next[x[clue]][y[clue]] = 'U';

            if (cur == player) {
                if (player == 'R') {
                    nextreds--;
                    if (nextreds == 0) {
                        best = 1;
                        dp[state][player] = best+1;
                        return best;
                    }
                } else {
                    nextblues--;
                    if (nextblues == 0) {
                        best = 1;
                        dp[state][player] = best+1;
                        return best;
                    }
                }
            } else {
                // not good - have to break

                if (cur == 'R' || cur == 'B') { // must be the opponents
                    if (player == 'R') {
                        nextblues--;
                        if (nextblues == 0) ok = 0;
                    } else {
                        nextreds--;
                        if (nextreds == 0) ok = 0;
                    }
                } else if (cur == 'A') ok = 0;

                break;
            }
        }


        if (ok) {
            best = max(best, 1 - win(next, other(player), nextblues, nextreds));
        } 
    }

    dp[state][player] = best+1;
    return best;
}

void solve() {
	
    REP(i,0,4) REP(j,0,4) {
        cin >> words[i][j];
        x[words[i][j]] = i;
        y[words[i][j]] = j;
    }

    vector<string> grid(4);
    REP(i,0,4) cin >> grid[i];

    ll n;
    cin >> n;
    hints.resize(n);
    REP(i,0,n) {
        string a;
        ll b;
        cin >> a >> b;
        hints[i].resize(b);
        REP(j,0,b) cin >> hints[i][j];
        sort(all(hints[i]));
    }

    if (win(grid, 'B', 5, 4)) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}