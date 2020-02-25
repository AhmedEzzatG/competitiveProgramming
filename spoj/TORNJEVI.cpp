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
typedef vector<vector<int>> matrix;
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
int n;

vector<vector<int>> scc;
vector<set<int>> dag, adj;
vector<int> dfs_num, dfs_low, compId;
vector<bool> inStack;
stack<int> stk;
int timer;

void tarjan(int node) {
	dfs_num[node] = dfs_low[node] = ++timer;
	stk.push(node);
	inStack[node] = 1;
	for (int child : adj[node])
		if (!dfs_num[child]) {
			tarjan(child);
			dfs_low[node] = min(dfs_low[node], dfs_low[child]);
		}
		else if (inStack[child])
			dfs_low[node] = min(dfs_low[node], dfs_num[child]);
	if (dfs_low[node] == dfs_num[node]) {
		scc.push_back(vector<int>());
		int v = -1;
		while (v != node) {
			v = stk.top(); stk.pop();
			inStack[v] = 0;
			scc.back().push_back(v);
			compId[v] = scc.size() - 1;
		}
	}
}

void SCC() {
	timer = 0;
	dfs_num = dfs_low = compId = vector<int>(adj.size());
	inStack = vector<bool>(adj.size());
	scc = vector<vector<int>>();
	for (int i = 1; i < adj.size(); i++)
		if (!dfs_num[i]) tarjan(i);
}

void DAG() {
	dag = vector<set<int>>(scc.size());
	for (int i = 1; i < adj.size(); i++)
		for (int j : adj[i]) if (compId[i] != compId[j])
			dag[compId[i]].insert(compId[j]);
}

int Not(int x) {
	return(x > n ? x - n : x + n);
}

void addEdge(int a) {
	adj[Not(a)].insert(a);
}
void addEdge(int a, int b) {
	adj[Not(a)].insert(b);
	adj[Not(b)].insert(a);
}

bool _2SAT(vector<int>& value) {
	SCC();
	for (int i = 1; i <= n; i++)
		if (compId[i] == compId[Not(i)])
			return false;
	vector<int> assign(scc.size(), -1);
	for (int i = 0; i < scc.size(); i++) if (assign[i] == -1) {
		assign[i] = true;
		assign[compId[Not(scc[i].back())]] = false;
	}
	for (int i = 1; i <= n; i++)value[i] = assign[compId[i]];
	return true;
}

vector<string> s;
map<pair<int, int>, int> id;
bool valid(int i, int j) {
	return 0 <= i && i < sz(s) && 0 <= j && j < sz(s[i]);
}

void go(int i, int j, int k) {
	int cur = id[{i, j}], idx = -1;
	i += dr[k], j += dc[k];
	while (valid(i, j)) {
		if (s[i][j] == '#')return;
		if (s[i][j] == 'T') { idx = id[{i, j}]; break; }
		i += dr[k], j += dc[k];
	}
	if (~idx) {
		if (k == 0 || k == 4)cur += sz(id), idx += sz(id);
		if (k < 4)addEdge(Not(cur)), addEdge(idx);
		else addEdge(cur), addEdge(Not(idx));
	}
}

int findTower(int i, int j, int k) {
	i += dr[k], j += dc[k];
	while (valid(i, j)) {
		if (s[i][j] == '#')return -1;
		if (s[i][j] == 'T') return id[{i, j}];
		i += dr[k], j += dc[k];
	}
	return -1;
}

int main() {
	run();
	int r, c;
	cin >> r >> c;
	s = vector<string>(r);
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		cin >> s[i];
		for (int j = 0; j < c; j++) if (s[i][j] == 'T')
			id[{i, j}] = ++cnt;
	}
	n = cnt * 2;
	adj = vector<set<int>>(2 * n + 1);
	for (int i = 0; i < r; i++)for (int j = 0; j < c; j++) {
		if (s[i][j] == 'T') {
			for (int k = 0; k < 8; k += 2)
				go(i, j, k);
		}
		else if (s[i][j] == 'n') {
			int up = findTower(i, j, 0);
			int right = findTower(i, j, 2);
			int down = findTower(i, j, 4);
			int left = findTower(i, j, 6);
			if ((up != -1) ^ (down != -1)) {
				int cur = (up == -1 ? down + sz(id) : Not(up + sz(id)));
				if ((left != -1) ^ (right != -1)) {
					int curL = (right == -1 ? left : Not(right));
					addEdge(cur, curL);
				}
				else addEdge(cur);
			}
			else if ((left != -1) ^ (right != -1)) {
				int curL = (right == -1 ? left : Not(right));
				addEdge(curL);
			}
		}
	}
	vector<int> value(n + 1);
	if (!_2SAT(value))RT(-1);
	char ch[] = { '1','2','4','3' };
	for (auto it : id) {
		s[it.first.first][it.first.second]
			= ch[value[it.second] + 2 * value[it.second + sz(id)]];
	}
	for (auto it : s)
		cout << it << endl;
}
