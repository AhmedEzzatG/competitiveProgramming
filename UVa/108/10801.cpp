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

const int N = 5 * 100;
int adj[N][N], vis[N], dis[N];
int n, k;

vector<int> input() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	vector<int> rt;
	int x;
	while (ss >> x)
		rt.push_back(x);
	return rt;
}

int dijkstra(int cur) {
	memset(vis, 0, sizeof(vis));
	memset(dis, oo, sizeof(dis));
	dis[cur] = 0;
	vis[cur] = true;
	while (true) {
		if (cur % 100 == k)
			return dis[cur];
		int mn = oo, idx = 0;
		for (int nxt = 0; nxt < n * 100; nxt++) {
			if (vis[nxt])
				continue;
			if (dis[cur] + adj[cur][nxt] < dis[nxt])
				dis[nxt] = dis[cur] + adj[cur][nxt];

			if (dis[nxt] < mn)
				mn = dis[nxt], idx = nxt;
		}
		if (mn == oo)
			break;
		cur = idx;
		vis[cur] = true;
	}
	return oo;
}

void Min(int &a, int b) {
	if (b < a)
		a = b;
}

int main() {
	run();
	while (cin >> n >> k) {
		memset(adj, oo, sizeof(adj));
		for (int i = 0; i < n * 100; i++)
			adj[i][i] = 0;
		vector<int> T(n);
		for (int i = 0; i < n; i++)
			cin >> T[i];
		cin.ignore();
		for (int i = 0; i < n; i++) {
			vector<int> tmp = input();
			for (auto &x : tmp)
				for (auto &y : tmp)
					Min(adj[i * 100 + x][i * 100 + y], abs(x - y) * T[i]);
		}
		for (int i = 0; i < 100; i++)
			for (int x = 0; x < n; x++)
				for (int y = 0; y < n; y++)
					Min(adj[x * 100 + i][y * 100 + i], 60);
		int ans = oo;
		for (int i = 0; i < n; i++)
			ans = min(ans, dijkstra(100 * i));
		if (ans < oo)
			cout << ans << endl;
		else
			cout << "IMPOSSIBLE\n";
	}
}