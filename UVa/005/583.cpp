#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x) << " = " << x << endl
#define numOfDigit(x) (int)(floor(1+log10(x)))
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
const int N = 1e6 + 5;
vector<bool> isPrime(N , true);
vector<int> prime(N);
int sz = 0;
void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < N; i += 2)isPrime[i] = false;
	for (int i = 3; i * i < N; i += 2) {
		if (isPrime[i]) {
			for (int j = 3 * i; j < N; j += i + i)
				isPrime[j] = false;
		}
	}
}

void getPrimes() {
	sieve();
	prime[sz] = 2, sz++;
	for (int i = 3; i < N; i += 2) {
		if (isPrime[i])
			prime[sz++] = i;
	}
}

int main() {
	Fast;
	file();
	int n;
	getPrimes();
	while (cin >> n, n) {
		cout << n << " = ";
		bool na = n < 0, b = 0;
		if (na) {
			cout << "-1 x "; n *= -1;
		}
		int i = 0;
		while (i < sz && prime[i] * prime[i] <= n) {
			while (n % prime[i] == 0) {
				if (b)cout << " x ";
				cout << prime[i];
				n /= prime[i];
				b = 1;
			}
			i++;
		}
		if (n > 1) {
			if (b)cout << " x ";
			cout << n;
		}
		cout << endl;
	}
}
