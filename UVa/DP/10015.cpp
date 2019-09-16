#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

const int MAX = 3501, N = 4e4;
int mem[MAX + 1][MAX];
bool isPrime[N + 1];
vector<int> prime;
void sieve() {
	clr(isPrime, true);
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

int solve(int index, int n) {
	if (n == 1)return 0;
	int& rt = mem[index][n];
	if (~rt)return rt;
	return rt = (solve(index + 1, n - 1) + prime[index]) % n;
}

int main() {
	run();
	sieve();
	clr(mem, -1);
	int n;
	while (cin >> n, n) {
		cout << solve(0, n) + 1 << endl;
	}
}
