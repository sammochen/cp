# simple.cpp

```c++
#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define sz(x) (ll)x.size()

void solve() {
	
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}
```

# template.cpp

```c++
#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define fe(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define lg(x) (ll)x.length()
#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pqueue priority_queue

struct FASTINPUT {
	void f(string & s) { char buf[400005]; ll a = scanf("%s", buf); a++; s = buf; }
	void f(ll & x) { ll a = scanf("%lld", &x); a++; }
	void f(int & x) { ll a = scanf("%d", &x); a++; }
	void f(double & x) { ll a = scanf("%lf", &x); a++; }
	template <typename A, typename B> void f(pair<A,B> & p) { f(p.first); f(p.second); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) f(y); }
	
	void read() {}
	template <typename Head, typename... Tail> void read(Head & H, Tail & ... T) { f(H); read(T...); }
};

struct FASTOUTPUT {
	void f(string s) { printf("%s", s.c_str()); }
	void f(ll x) { printf("%lld", x); }
	void f(int x) { printf("%d", x); }
	void f(double x) { printf("%.20f", x); }
	void f(char x) { printf("%c", x); }
	void f(const char* a) { printf("%s", a); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) { f(y); f(" ");}  }


	void print() {}
	template <typename Head, typename... Tail> void print(Head H, Tail ... T) { f(H); print(T...); }
};

struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#define fin(...) do { FASTINPUT inp; inp.read(__VA_ARGS__); } while (false)
#define fout(...) do { FASTOUTPUT out; out.print(__VA_ARGS__); } while (false)
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";


void solve() {
	
}

signed main() {
	ll t = 1;
	// fin(t);
	rep(i,0,t) solve();
	return 0;
}
```

# compilers
```
g++ -std=c++14 A.cpp 
g++ -Wall -Wextra -pedantic -std=c++14 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector A.cpp 
```
# articulation.cpp
```c++
void dfs(ll at, ll prev, VVLL & E, VLL & tin, VLL & low, VLL & ans, ll & t, ll & root) {
	tin[at] = t;
	low[at] = t;
	t++;

	ll k = 0;
	fe(to, E[at]) {
		if (tin[to] == -1) {
			k++;
			dfs(to, at, E, tin, low, ans, t, root);
			upmin(low[at], low[to]);

			if (at != root && low[to] >= tin[at]) {
				ans[at] = 1;
			} else if (at == root && k > 1) {
				ans[at] = 1;
			}
		} else if (to != prev) {
			upmin(low[at], tin[to]);
		}
	}
}

VLL ap(VVLL & E) {
	ll n = E.size();
	ll t = 1;
	VLL tin(n, -1), low(n, -1), ans(n);

	rep(i,0,n) {
		if (tin[i] == -1) {
			dfs(i, -1, E, tin, low, ans, t, i);
		}
	}
	
	return ans;
}
```

# bridge.cpp
```c++
ll time;

void dfs(ll at, ll prev, VVLL & E, VLL & first, VLL & low, set<PLL> & bridge) {
	first[at] = time;
	low[at] = time;
	time++;
	for (ll to : E[at]) {
		if (to == prev) continue;
		
		if (first[to] == -1) {
			dfs(to, at, E, first, low, bridge);
			low[at] = min(low[at], low[to]);
			if (low[to] > first[at]) {
				bridge.insert({min(at,to), max(at,to)});
			}
		} else {
			low[at] = min(low[at], first[to]);
		}
	}
}	
```
# dinic.cpp
```c++

namespace maxFlow {
    const ll maxn = 350, maxe = 10010, source = maxn - 1, sink = maxn - 2;
    ll cnt = 0;
    
    struct edge {
        ll from, to, cap;
        
        edge(ll a, ll b, ll c) : from(a), to(b), cap(c) {}
        
        edge() {
            from = to = cap = 0;
        }
    };
    
    vector<ll> g[maxn];
    edge e[maxe];
    
    void clear() {
        cnt = 0;
        REP(i, 0, maxn) g[i].clear();
        REP(i, 0, maxe) e[i] = edge();
    }
    
    void addEdge(ll u, ll v, ll cap) {
        ll cur = cnt;
        e[cur] = edge(u, v, cap);
        g[u].push_back(cur);
        e[cur ^ 1] = edge(v, u, 0);
        g[v].push_back(cur ^ 1);
        cnt += 2;
    }
    
    ll lvl[maxn], cur[maxn];
    
    bool bfs(ll start = source) {
        memset(lvl, -1, sizeof(lvl));
        memset(cur, 0, sizeof(cur));
        lvl[start] = 0;
        queue <ll> q;
        q.push(start);
        
        while (q.size()) {
            ll f = q.front();
            q.pop();
            for (auto curEdge:g[f]) {
                auto &E = e[curEdge];
                if (E.cap) {
                    if (lvl[E.to] == -1) {
                        lvl[E.to] = lvl[f] + 1;
                        q.push(E.to);
                    }
                }
            }
        }
        
        return lvl[sink] != -1;
    }
    
    
    ll dfs(ll curNode, ll curCap) {
        if (!curCap || curNode == sink)return curCap;
        ll ans = 0;
        for (ll &i = cur[curNode]; i < g[curNode].size(); i++) {
            ll curEdge = g[curNode][i];
            if (lvl[e[curEdge].to] > lvl[curNode]) {
                ll delta = dfs(e[curEdge].to, min(e[curEdge].cap, curCap));
                ans += delta;
                curCap -= delta;
                e[curEdge].cap -= delta;
                e[curEdge ^ 1].cap += delta;
                if (!curCap)break;
            }
        }
        return ans;
    }
    
    ll dinic() {
        ll ans = 0;
        while (bfs()) {
            ans += (dfs(source, inf));
        }
        return ans;
    }
}
```
# extendedgcd.cpp
```c++
// Function for extended Euclidean Algorithm  
ll gcde(ll a, ll b, ll & x, ll & y) {
    // Base Case  
    if (a == 0) {  
        x = 0;
        y = 1;  
        return b;  
    }  
  
    ll x1, y1; // To store results of recursive call  
    ll gcd = gcde(b%a, a, x1, y1);  
  
    // Update x and y using results of  
    // recursive call  
    x = y1 - (b/a) * x1;  
    y = x1;  
  
    return gcd;  
}  
```

# hash.cpp
```c++
struct hasher {
	string s;
	ll mod;
	ll seed = 31;
	VLL pow, val;

	ll toll(char c) {
		return c - 'a' + 1;
	}
	hasher(string str, ll m = 1000000207) {
		s = str;
		mod = m;

		pow.resize(s.length() + 1);
		val.resize(s.length() + 1);
		pow[0] = 1;
		rep(i,0,s.length()) {
			val[i+1] = (val[i] + toll(s[i]) * pow[i] % mod) % mod;
			pow[i+1] = (pow[i] * seed) % mod;
		}
	}

	ll f(ll i, ll j) {
		ll diff = (val[j+1] - val[i] + mod) % mod;
		// times this by how far away i is! 
		diff *= pow[s.length() - i];
		diff %= mod;
		return diff;
	}
};

```

# kmp.cpp
```c++
VLL kmp(string s) {
	ll n = s.length();
	VLL k(n);
	rep(i,1,n) {
		ll prev = k[i-1];
		while (prev && s[i] != s[prev]) {
			prev = k[prev - 1];
		}
		k[i] = prev + (s[i] == s[prev]);
	}
    return k;
}
```

# lis.cpp
```c++
ll bs(VLL & A, ll x) {
	ll L = 0, R = A.size() - 1;
	while (L < R) {
		ll M = (L + R) / 2;
		if (A[M] >= x) {
			R = M;
		} else {
			L = M + 1;
		}
	}
	return L;
}

ll lis(VLL & A) {
	VLL tails;
	for (ll a : A) {
		if (tails.size() == 0) {
			tails.push_back(a);
		} else if (a < tails[0]) {
			tails[0] = a;
		} else if (a > tails[tails.size() - 1]) {
			tails.push_back(a);
		} else {
			ll i = bs(tails, a);
			tails[i] = a;
		}
	}
	
	return tails.size();
}
```

# convexhull.cpp
```c++
struct point {
	ll x, y;
};

// returns 0 if collinear, 1 if clockwise, -1 if counterclockwise
ll cw(point a, point b, point c) {
	ll v = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
	return v == 0 ? 0 : v < 0 ? -1 : 1;
}

bool operator<(const point & a, const point & b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

vector<point> hull(vector<point> & A) {
	ll n = A.size();
	sort(A.begin(), A.end());
	vector<point> H(2*n);

	ll k = 0; // size
	rep(i,0,n) {
		while (k >= 2 && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	ll t = k+1;
	rrep(i,n-2,0) { // takes it all the way to the end
		while (k >= t && cw(H[k-2], H[k-1], A[i]) == -1) {
			k--;
		}
		H[k++] = A[i];
	}

	H.resize(k-1); // discards the last one
	return H;
}
```

# phi.cpp
```c++
void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}

		P.push_back(x);
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
		}
	}
}

ll phi(ll x) {
    // find all prime factors, then it is x * product(1 - 1/p)
    ll ans = x;
    REP(i,0,P.size()) {
        if (P[i] * P[i] > x) break;
        if (x % P[i] == 0) {
            ans *= (P[i] - 1);
            ans /= P[i];
        }
        while (x % P[i] == 0) {
            x /= P[i];
        }
    }

    if (x != 1) {
        ans *= (x-1);
        ans /= x;
    }
    return ans;
}
```

# suffix array
```c++

const ll nax = 4e5 + 5;
ll P[nax];
ll L[nax][2][3];
ll sa[nax];
ll lcp[nax];

template<typename A> void arrdebug(A a[], ll n) {
	rep(i,0,n) {
		fout(a[i], ' ');
	}
	fout(nl);
}

void radixsort(ll ind, ll n, ll bucket, ll from, ll to) {
	VLL cnt(bucket); 
	rep(i,0,n) {
		cnt[L[i][from][ind]+1]++;
	}

	rep(i,1,bucket) cnt[i] += cnt[i-1];
	
	rrep(i,n-1,0) {
		--cnt[L[i][from][ind]+1];

		rep(j,0,3) {
			L[cnt[L[i][from][ind]+1]][to][j] = L[i][from][j];
		}
	}
}

void suffixarray(string & s) {
	ll n = lg(s);
	ll k = log2(n) + 2;
	
	rep(i,0,n) {
		P[i] = s[i]; // get initial rank
	}

	rep(i,1,k) {
		rep(j,0,n) {
			L[j][0][0] = P[j]; 
			L[j][0][1] = j + tp(i-1) < n ? P[j+tp(i-1)] : -1;
			L[j][0][2] = j;
		}

		ll buckets = n+1;
		if (i == 1) upmax(buckets, 256);
		radixsort(1, n, buckets, 0, 1);
		radixsort(0, n, buckets, 1, 0);	
		
		rep(j,0,n) {
			P[L[j][0][2]] = j && L[j-1][0][0] == L[j][0][0] && L[j-1][0][1] == L[j][0][1] ? P[L[j-1][0][2]] : j;
		}
	}

	rep(i,0,n) {
		sa[P[i]] = i;
	}

	VLL ind(n);
	rep(i,0,n) {
		ind[sa[i]] = i;
	}

	ll res = 0;
	rep(i,0,n-1) {
		ll index = ind[i] - 1;
		if (index < 0) continue;
		ll j = sa[index];

		rep(k,res,nax) {
			if (s[i+k] == s[j+k]) res++;
			else break;
		}
		lcp[index] = res;

		if (res) res--;
	}
}
```

# scc.cpp
```c++
ll cur_time;
VVLL scc;

void dfs(ll at, VVLL & E, VLL & first, VLL & low, stack<ll> & stack, VLL & onstack) {
	first[at] = cur_time;
	low[at] = cur_time;
	stack.push(at);
	onstack[at] = 1;
	cur_time++;

	for (ll to : E[at]) {
		if (first[to] == -1) {
			dfs(to, E, first, low, stack, onstack);
			low[at] = min(low[at], low[to]);
		} else if (onstack[to]) {
			low[at] = min(low[at], first[to]);
		}
	}

	if (first[at] == low[at]) {
		VLL comp;
		ll last;
		do {
			last = stack.top();
			comp.push_back(last);
			onstack[last] = 0;
			stack.pop();
		} while (last != at);

		scc.push_back(comp);
	}
}	

void go(ll n, VVLL & E) {
	cur_time = 1;
	VLL first(n, -1), low(n), onstack(n);
	stack<ll> stack;

	rep(i,0,n) {
		if (first[i] == -1) dfs(i, E, first, low, stack, onstack);
	}
}
```

# segtree.cpp
```c++

#define lson (ind<<1)
#define rson (ind<<1|1)

struct SegTree{
    static const ll maxn = 1e5+5;

    struct node{
        ll l,r;
    };

    node no[maxn*4];

    void push_up(ll ind){

    }
    void push_down(ll ind){

    }
    void build(ll l, ll r, ll ind){
        no[ind].l = l;
        no[ind].r = r;
        if(l == r){

        }else{
            ll mid = (l+r)/2;
            build(l,mid,lson);
            build(mid+1,r,rson);
            push_up(ind);
        }
    }
    void update(ll l, ll r, ll ind, ll val){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
        }else{
            push_down(ind);
            update(l,r,lson,val);
            update(l,r,rson,val);
            push_up(ind);
        }
    }
    void query(ll l, ll r, ll ind, ll & ans){
        if(l>no[ind].r || r<no[ind].l)return;
        if(l<=no[ind].l && no[ind].r <= r){
            
        }else{
            push_down(ind);
            query(l,r,lson,ans);
            query(l,r,rson,ans);
            push_up(ind);
        }
    }
};
``` 

# zfunction.cpp
```c++
VLL zf(string s) {
	ll n = s.length();
	VLL z(n);
	ll l = 0, r = 0;
	REP(i,1,n) {
		// if within the bound, update the z value
		if (i <= r) {
			z[i] = min(r-i+1, z[i-l]);
		}
		// push it up if you can - this might push the r value up
		while (i+z[i] < n && s[i+z[i]] == s[z[i]]) {
			z[i]++;
		}
		// if the value exceeds the bounds, update bound
		if (i+z[i] >= r) {
			r = i+z[i]-1;
			l = i;
		}
	}
	return z;
}
```

