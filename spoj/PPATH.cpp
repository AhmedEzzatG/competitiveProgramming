#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
const int N = 1e4;
bool isPrime[N];
void sieve() {
	clr(isPrime, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < N; i += 2) isPrime[i] = false;
	for (int i = 3; i * i < N; i += 2) {
		if (isPrime[i])
			for (int j = i * i; j < N; j += i + i)
				isPrime[j] = false;
	}
}

vector<int> adj[N];
int bfs(int st, int ed) {
	vector<int> dep(N, oo);
	queue<int> q; q.push(st);
	dep[st] = 0;
	int cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		if (cur == ed)break;
		for (int child : adj[cur])
			if (dep[child] > dep[cur] + 1) {
				q.push(child);
				dep[child] = dep[cur] + 1;
			}
	}
	return dep[ed];
}
int main() {
	run();
	sieve();
	for (int i = 1000; i < N; i++) {
		if (!isPrime[i])continue;
		for (int c = 1; c < N; c*= 10) {
			int x = i - (i / c) % 10 * c;
			for (int j = 0; j <= 9; j++) {
				x += j * c;
				if (x != i && isPrime[x])
					adj[i].push_back(x);
				x -= j * c;
			}
		}
	}
	int t; cin >> t;
	while (t--) {
		int st, ed;
		cin >> st >> ed;
		cout << bfs(st, ed) << endl;
	}
}
