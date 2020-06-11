ll width = 4;
void myset(ll & mask, ll ind, ll v) {
	ll ones = (1<<width) - 1;
	mask &= ~(ones << (ind * width));

	mask |= (v << (ind * width));
}

ll myget(ll & mask, ll ind) {
	ll ones = (1<<width) - 1;
	return (mask >> (ind * width)) & ones;
}