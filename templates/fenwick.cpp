#define lsb(i) ((i)&-(i))

const ll nax = 2e5 + 5;

struct fenwick {
	ll arr[nax] = {0};

	void add(ll i, ll k) {
		while (i < nax) {
			arr[i] += k;
			i += lsb(i);
		}
	}

	ll sum(ll i) {
		ll total = 0;
		while (i > 0) {
			total += arr[i];
			i -= lsb(i);
		}
		return total;
	}
};

void solve() {

}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}