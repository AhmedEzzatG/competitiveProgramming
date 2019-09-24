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

const int MAX = 101;
int mem[MAX][MAX], sz[MAX], in[MAX];
vector<vii> temp, adj;
bitset<MAX> vis;
bool dfs(int node, int par) {
	vis[node] = 1;
	int cnt = 0;
	for (auto child : temp[node]) {
		if (child.first == par)continue;
		if (vis[child.first])return 0;
		dfs(child.first, node);
		cnt++;
	}
	return cnt <= 2;
}

void buildTree(int node, int par) {
	for (auto child : temp[node]) {
		if (child.first == par)continue;
		adj[node].push_back(child);
		buildTree(child.first, node);
		sz[node] += sz[child.first] + 1;
	}
}
int solve(int node, int q) {
	if (q < 0 || sz[node] < q)return -oo;
	if (sz[node] == q)return 0;
	int& rt = mem[node][q];
	if (~rt)return rt;
	rt = 0;
	if (sz(adj[node]) == 1) {
		int next = adj[node][0].first, w = adj[node][0].second;
		rt = w + solve(next, q);
	}
	else {
		ii ch1 = adj[node][0], ch2 = adj[node][1];
		for (int i = 0; i <= q; i++) {
			rt = max(rt, ch1.second + ch2.second + solve(ch1.first, i) + solve(ch2.first, q - i));
			if (sz[ch1.first] + 1 == i)
				rt = max(rt, ch2.second + solve(ch2.first, q - i));
			if (sz[ch2.first] + 1 == q - i)
				rt = max(rt, ch1.second + solve(ch1.first, i));
		}
	}
	return rt;
}
int main() {
	run();
	clr(mem, -1);
	int n, q;
	cin >> n >> q;
	temp = adj = vector<vii>(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		temp[u].emplace_back(v, w);
		temp[v].emplace_back(u, w);
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		vis = 0;
		if (dfs(i, -1) && vis.count() == n) { root = i; break; }
	}
	buildTree(root, -1);
	cout << max(0, solve(root, n - 1 - q));
}
