VI A;

void msort(ll L, ll R) {
	if (L >= R) return;
	
	ll M = (L+R)/2;
	msort(L, M);
	msort(M+1, R);
	
	VI temp;
	ll x = 0, y = 0;
	ll n = M-L+1, m = R-M;

	while (x < n && y < m) {
		if (A[x + L] < A[y + M+1]) temp.pb(A[x++ + L]);
		else temp.pb(A[y++ + M+1]);
	}
	
	while (x < n) {
		temp.pb(A[x++ + L]);
	}
	
	while (y < m) {
		temp.pb(A[y++ + M+1]);
	}
	
	rep(i,L,R+1) A[i] = temp[i-L];
	return;
}
