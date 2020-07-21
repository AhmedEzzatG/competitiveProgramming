#include<bits/stdc++.h>
using namespace std;

unsigned long long nCr(int n, int r) {
	if (r > n)
		return 0;
	r = max(r, n - r); //nCr(n,r) = nCr(n,n-r)
	unsigned long long ans = 1, div = 1, i = r + 1;
	while (i <= n) {
		ans *= i;
		i++;
		ans /= div;
		div++;
	}
	return ans;
}

unsigned long long nPr(int n, int r) {
	if (r > n)
		return 0;
	unsigned long long p = 1, i = n - r + 1;
	while (i <= n)
		p *= i++;
	return p;
}

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	while (a != 0 && b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a / gcd(a, b) * b;
}

void prime_factors(int n) {
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			cout << i << ' ' << cnt << endl;
		}
	}
}

void prime_factors_sqrt(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			cout << i << ' ' << cnt << endl;
		}
	}
	if (n > 1) {
		cout << n << ' ' << 1 << endl;
	}
}

int main() {
}
