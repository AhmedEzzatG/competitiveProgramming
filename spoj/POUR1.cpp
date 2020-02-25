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
const int oo = INT_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-5;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
}
int a, b, c;
int bfs() {
	queue<pair<int, int>> q;
	map<pair<int, int>, bool> vis;
	int dep = 0;
	q.push({ 0,0 });
	vis[{0, 0}] = 1;
	while (!q.empty()) {
		int sz = sz(q);
		while (sz--) {
			int x = q.front().first, y = q.front().second;
			if (x == c || y == c)
				return dep;
			q.pop();
			int xx = min(x, b - y), yy = min(y, a - x);
			vector<pair<int, int>> v = { { 0,y } , { a,y } , { x,0 } ,
				{ x,b } , { x - xx,y + xx } , { x + yy, y - yy } };
			for (auto p : v) {
				xx = p.first, yy = p.second;
				if (vis.find({ xx,yy }) == vis.end()) {
					q.push({ xx,yy });
					vis[{xx, yy}] = 1;
				}
			}
		}
		dep++;
	}
	return -1;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (c > a&& c > b)
			cout << -1 << endl;
		else
			cout << bfs() << endl;
	}
}
