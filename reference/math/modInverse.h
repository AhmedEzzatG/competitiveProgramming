#define ll long long

ll power(ll x, ll y, int mod) {
	if (y == 0) return 1;
	if (y == 1) return x % mod;
	ll r = power(x, y >> 1, mod);
	return (((r * r) % mod) * power(x, y & 1, mod)) % mod;
}

// (a / b) % mod = (a% mod) * (b ^ (mod - 2))%mod
// Modular inverse of the given number modulo mod
// return z = (1/b) % mod // mod must be Prime
ll modInverse(ll b, ll mod) {
	return power(b, mod - 2, mod);
}

// Calulate Modular inverse
ll modInv(ll a, ll m) {
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
		return 0;
	while (a > 1) {
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
		x1 += m0;
	return x1;
}
