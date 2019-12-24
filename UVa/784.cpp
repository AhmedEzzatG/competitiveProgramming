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
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
#define oo INT_MAX
int dr[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
vector<string> maze;
bool valid(int i, int j) {
	return 0 <= i && i < sz(maze) && 0 <= j &&
		j < sz(maze[i]) && maze[i][j] == ' ';
}

void dfs(int i, int j) {
	maze[i][j] = '#';
	for (int k = 0; k < 4; k++) {
		int x = i + dr[k], y = j + dc[k];
		if (valid(x, y))
			dfs(x, y);
	}
}

int main() {
	run();
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		int i = 0, j = 0;
		bool get = false;
		while (getline(cin, s)) {
			if (s.find('_') != string::npos)break;
			maze.push_back(s);
			if (!get) {
				if (s.find('*') == string::npos)
					i++;
				else {
					j = s.find('*'); get = 1;
				}
			}
		}
		dfs(i, j);
		for (auto ss : maze)
			cout << ss << endl;
		cout << s << endl;
		maze.clear();
	}
}
