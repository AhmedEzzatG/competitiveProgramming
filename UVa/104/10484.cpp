#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

const int N = 1e8;
bool isPrime[N + 1];
vector<int> prime;
void sieve() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i <= N; i += 2) isPrime[i] = false;
	for (int i = 3; i * i <= N; i += 2) {
		if (isPrime[i])
			for (int j = i * i; j <= N; j += i + i)
				isPrime[j] = false;
	}
	prime.push_back(2);
	for (int i = 3; i <= N; i += 2)
		if (isPrime[i]) prime.push_back(i);
}

map<int, int> prime_factors(ll n) {
	map<int, int> p;
	int idx = 0;
	while (!(n <= N && isPrime[n]) && idx < prime.size()
			&& (ll) prime[idx] * prime[idx] <= n) {
		int cnt = 0;
		while (n % prime[idx] == 0)
			n /= prime[idx], cnt++;
		if (cnt)
			p[prime[idx]] = cnt;
		idx++;
	}
	if (n > 1)
		p[n]++;
	return p;
}

ll numOfDivisors(const map<int, int> &mp) {
	ll cnt = 1;
	for (auto it : mp)
		cnt *= (it.second + 1);
	return cnt;
}

int main() {
	run();
	sieve();
	vector<map<int, int>> fact(101);
	for (int i = 1; i <= 100; i++) {
		map<int, int> mp = prime_factors(i);
		fact[i] = fact[i - 1];
		for (auto &it : mp)
			fact[i][it.first] += it.second;
	}
	int n, d;
	while (cin >> n >> d, n || d) {
		map<int, int> mp = prime_factors(d);
		bool valid = true;
		auto p = fact[n];
		for (auto &it : mp) {
			p[it.first] -= it.second;
			if (p[it.first] < 0)
				valid = false;
		}
		cout << (valid ? numOfDivisors(p) : 0) << endl;
	}
}
