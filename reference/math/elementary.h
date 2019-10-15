#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define EPS 1e-8
#define numOfDigit(x) 1+(int)(floor(log10(x)))
#define numOfBits(x) 1+(int)(floor(log2(x)))

int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

ll gcd(ll a, ll b) { return !b ? abs(a) : gcd(b, a % b); }

ll lcm(ll a, ll b) { return abs(a / gcd(a, b)) * b; }

//return sum of sequence a, a+x , a+2x .... b
ll sequence(ll a, ll b, ll x) {
	a = ((a + x - 1) / x) * x;
	b = (b / x) * x;
	return (b + a) * (b - a + x) / (2 * x);
}

ll power(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll r = power(x, y >> 1);
	return r * r * power(x, y & 1);
}

//sum 1/(x^i) for i = 1 to n
double summation(int x, int n) {
	double p = power(x, n);
	return(p - (x - 1.0)) / p;
}
