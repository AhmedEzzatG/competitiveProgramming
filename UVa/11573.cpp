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
const double PI = acos(-1), EPS = 1e-3;
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
const int N = 1009;
int n, m;
int v[N][N], dep[N][N];
bool valid(int i, int j) {
	return 0 < i && i <= n && 0 < j && j <= m;
}
int bfs(pair<int, int> st, pair<int, int>ed) {
	clr(dep, oo);
	deque<pair<int, int>> q;
	q.push_back(st);
	dep[st.first][st.second] = 0;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop_front();
		for (int k = 0; k < 8; k++) {
			int x = i + dr[k], y = j + dc[k],
				w = (k != v[i][j]);
			if (valid(x, y) && dep[x][y] > dep[i][j] + w) {
				dep[x][y] = dep[i][j] + w;
				if (w)q.emplace_back(x, y);
				else q.emplace_front(x, y);
			}
		}
	}
	return dep[ed.first][ed.second];
}
int main() {
	run();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch; cin >> ch;
			v[i][j] = ch - '0';
		}
	int x; cin >> x;
	while (x--) {
		pair<int, int> st, ed;
		cin >> st.first >> st.second >> ed.first >> ed.second;
		cout << bfs(st, ed) << endl;
	}
}
