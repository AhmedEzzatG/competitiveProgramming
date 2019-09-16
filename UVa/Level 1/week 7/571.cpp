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
const int oo = 1e8, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
#endif
}

int a, b, c;
string st[]{ "empty A","fill A","empty B","fill B", "pour A B","pour B A" };
void bfs() {
	queue<pair<int, int>> q;
	map<pair<int, int>, pair<int, int>> par;
	map<pair<int, int>, string> s;
	q.push({ a,0 });
	q.push({ 0,b });
	par[{a, 0}] = par[{0, b}] = par[{0, 0}] = { 0,0 };
	s[{a, 0}] = "fill A";
	s[{0, b}] = "fill B";
	pair<int, int> end = { 0,0 };
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		if (y == c) {
			end = { x,y };
			break;
		}
		q.pop();
		int xx = min(x, b - y), yy = min(y, a - x);
		vector<pair<int, int>> v = { { 0,y } , { a,y } , { x,0 } ,
				{ x,b } , { x - xx,y + xx } , { x + yy, y - yy } };
		for (int i = 0; i < sz(v); i++) {
			if (par.find(v[i]) == par.end()) {
				s[v[i]] = st[i];
				q.push(v[i]);
				par[v[i]] = { x,y };
			}
		}
	}
	vector<string> ans;
	while (end.first || end.second) {
		ans.push_back(s[end]);
		end = par[end];
	}
	reverse(all(ans));
	ans.push_back("success");
	cout << ans[0];
	for (int i = 1; i < sz(ans); i++)
		cout << endl << ans[i];
}

int main() {
	run();
	while (cin >> a >> b >> c) {
		bfs();
		cout << endl;
	}
}
