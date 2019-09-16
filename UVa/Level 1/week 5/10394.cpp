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
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
const int N = 20000000;
vector<bool> prime(N + 1, true);
vector<bool> Sieve(int n = N) {
	prime[0] = prime[1] = false;
	for (int i = 4; i <= n; i += 2) prime[i] = false;
	for (int i = 3; i * i <= n; i += 2) {
		if (prime[i])
			for (int j = 3 * i; j <= n; j += i + i)
				prime[j] = false;
	}
	return prime;
}

int main() {
	Fast;
	file();
	Sieve();
	vector<pair<int, int>> v;
	for (int i = 3; i < 20000000; i += 2) {
		if (!prime[i + 2])i += 2;
		else if (prime[i]) {
			v.push_back({ i,i + 2 });
		}
	}
	int n;
	while (cin >> n) {
		cout << "(" << v[n - 1].first << ", " <<
			v[n - 1].second << ")" << endl;
	}
}
