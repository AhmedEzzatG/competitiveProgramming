#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v) return cout<<v,0
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MAX
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}
int n;
vector<vector<bool>> v, vis;
bool valid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n && !vis[i][j] && v[i][j] == 1;
}
void dfs(int i,int j) {
	vis[i][j] = true;
	for (int k = 0; k < 8; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y))dfs(x, y);
	}
}

int cnt() {
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (valid(i, j)) {
				dfs(i, j);
				c++;
			}
	return c;
}
int main() {
	run();
	int I = 1;
	while (cin >> n) {
		cout << "Image number " << I++;
		v.clear(); vis.clear();
		v.resize(n, vector<bool>(n)); vis.resize(n, vector<bool>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				char x; cin >> x;
				if (x == '1') v[i][j] = 1;
			}
		cout << " contains "<< cnt() << " war eagles." << endl;

	}
}
