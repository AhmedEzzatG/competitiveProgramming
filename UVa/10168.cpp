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
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

const int N = 10000000;
bool isPrime[N + 1];
int previous[N + 1];
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
	int prv = 0;
	for (int i = 2; i <= N; i++) {
		previous[i] = prv;
		if (isPrime[i])prv = i;
	}
}


int main() {
	run();
	sieve();
	int n; 
	while (cin >> n) {
		if (n < 8) {
			cout << "Impossible.\n";
			continue;
		}
		vector<int> out;
		for (int i = 3; i >= 0; i--) {
			int cur = n;
			while (n - cur < 2 * i)
				cur = previous[cur];
			cout << cur << " \n"[i == 0];
			n = n - cur;
			cur = n;
		}
	}
}