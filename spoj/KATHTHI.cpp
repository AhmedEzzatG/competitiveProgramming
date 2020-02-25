#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
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

vector<string> v;
bool valid(int i, int j) {
	return 0 <= i && i < sz(v) && 0 <= j && j < sz(v[i]);
}

int bfs() {
	deque<pair<int, int>> q;
	vector<vector<int>> dis(sz(v), vector<int>(sz(v[0]), oo));
	q.emplace_back(0, 0);
	dis[0][0] = 0;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop_front();
		for (int k = 0; k < 8; k += 2) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y)) {
				int c = v[i][j] != v[x][y];
				if (dis[x][y] > dis[i][j] + c) {
					dis[x][y] = dis[i][j] + c;
					if (c)q.emplace_back(x, y);
					else q.emplace_front(x, y);
				}
			}
		}
	}
	return dis[sz(v) - 1][sz(v[0]) - 1];
}
int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		v = vector<string>(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		cout << bfs() << endl;
	}

}
