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
vector<vector<char>> v;
vector<vector<bool>> vis;
bool valid(int i, int j) {
	return 0 <= i && i < sz(v) && 0 <= j && j < sz(v[0])
		&& !vis[i][j] && v[i][j] != '.';
}

void dfsX(int i, int j) {
	v[i][j] = '*';
	for (int k = 0; k < 8; k += 2) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y) && v[x][y] == 'X') dfsX(x, y);
	}
}

int dfs(int i, int j) {
	vis[i][j] = 1;
	int cnt = 0;
	for (int k = 0; k < 8; k += 2) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y)) {
			if (v[x][y] == 'X') { dfsX(x, y); cnt++; }
			cnt += dfs(x, y);
		}
	}
	return cnt;
}

int main() {
	run();
	int n, m;
	int I = 0;
	while (cin >> m >> n, n || m) {
		cout << "Throw " << ++I << endl;
		v = vector<vector<char>>(n, vector<char>(m));
		vis = vector<vector<bool>>(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> v[i][j];
		vector<int> o;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (valid(i, j)) {
					int cnt = 0;
					if (v[i][j] == 'X') { dfsX(i, j); cnt++; }
					cnt += dfs(i, j);
					o.push_back(cnt);
				}
		sort(all(o));
		for (int i = 0; i < sz(o); i++) {
			if (i) cout << ' ';
			cout << o[i];
		}
		cout << endl << endl;
	}
}