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

bool go(int x, int y, int dx, int dy,char ch, vector<vector<char>> & v) {
	set<char> st;
	for (int i = 0; i < 3; i++) {
		if (v[x][y] != ch)return 0;
		st.insert(v[x][y]);
		x += dx; y += dy;
	}
	return (sz(st) == 1);
}
bool win(int i, int j, vector<vector<char>>& v) {
	return (go(i, 0, 0, 1, v[i][j], v) || go(0, j, 1, 0, v[i][j], v)
		|| go(0, 0, 1, 1, v[i][j], v) || go(0, 2, 1, -1, v[i][j], v));
}

set<vector<vector<char>>> st;
void bfs() {
	vector<vector<char>> v(3, vector<char>(3, '.'));
	queue <pair<vector<vector<char>>, bool>> q;
	set<vector<vector<char>>> vis;
	st.insert(v);
	q.push({ v,1 });
	while (!q.empty()) {
		v = q.front().first;
		bool b = q.front().second;
		q.pop();
		if (vis.find(v) != vis.end())continue;
		vis.insert(v);
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (v[i][j] == '.') {
					v[i][j] = (b ? 'X' : 'O');
					if (st.find(v) == st.end())st.insert(v);
					if (!win(i, j, v))
						q.push({ v,!b });
					v[i][j] = '.';
				}
	}

}
int main() {
	run();
	bfs();
	int t; cin >> t;
	while (t--) {
		vector<vector<char>> v(3, vector<char>(3, '.'));
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cin >> v[i][j];
		}
		string s;
		getline(cin,s);
		if (st.find(v) != st.end())cout << "yes\n";
		else cout << "no\n";
	}
}
