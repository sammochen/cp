
void rowflip(VVDB & A, ll i, ll j) {
	VDB temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void rowmult(VVDB & A, ll i, db k) {
	rep(j,0,A.size()) {
		A[i][j] *= k;
	}
}

void rowaddmult(VVDB & A, ll i, ll j, db k) {
	rep(x,0,A.size()) {
		A[i][x] += k * A[j][x];
	}
}

VVDB identity(ll n) {
	VVDB A(n, VDB(n));
	rep(i,0,n) {
		A[i][i] = 1;
	}
	return A;
}

VVDB inverse(VVDB A) {
	ll n = A.size();
	VVDB I = identity(n);

	rep(p,0,n) {
		rep(x,p,n) {
			if (A[x][p] != 0) {
				rowflip(I, x, p);
				rowflip(A, x, p);
				break;
			}
		}

		rowmult(I, p, 1 / A[p][p]);
		rowmult(A, p, 1 / A[p][p]);

		rep(r,0,n) {
			if (r == p) continue;

			rowaddmult(I, r, p, -A[r][p]);
			rowaddmult(A, r, p, -A[r][p]);
		}
		
	}
	return I;
}

VVDB operator*(VVDB a, VVDB b) {
	VVDB c(a.size(), VDB(b[0].size()));
	
	rep(i,0,a.size()) {
		rep(j,0,a[0].size()) {
			rep(k,0,b[0].size()) {
				c[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	
	return c;			
}

// needed for precision
unsigned long long llpow(unsigned long long a, unsigned long long b) {
	if (b == 0) return 1;
	unsigned long long c = llpow(a, b/2);
	c = c * c;
	if (b%2) c *= a;
	return c;
}
