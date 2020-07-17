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
	freopen("output.out", "w", stdout);
#else
#endif
}
vector<vector<int>> v;
bool valid(int i, int j) {
	return 0 <= i && i < sz(v) && 0 <= j && j < sz(v[i]);
}
struct edge {
	int x, y, weight;
	edge(int x, int y, int weight) :x(x), y(y), weight(weight) {}
	bool operator <(const edge& other)const {
		return weight > other.weight;
	}
};

int dijkstra() {
	priority_queue <edge> q;
	vector<vector<int>> dis(sz(v), vector<int>(sz(v[0]), oo));
	dis[0][0] = v[0][0];
	q.push(edge(0, 0, v[0][0]));
	while (!q.empty()) {
		int i = q.top().x, j = q.top().y, w = q.top().weight; q.pop();
		if (w > dis[i][j])continue;
		for (int k = 0; k < 8; k += 2) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y) && dis[x][y] > dis[i][j] + v[x][y]) {
				dis[x][y] = dis[i][j] + v[x][y];
				q.push(edge(x, y, dis[x][y]));
			}
		}
	}
	return dis[sz(v) - 1][sz(v[0]) - 1];

}

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		v = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		cout << dijkstra() << endl;
	}
}