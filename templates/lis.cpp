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
