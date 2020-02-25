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

string swapIn(string s, int i, int j) {
	string tmp = s;
	s[i * 3 + j] = tmp[(i + 1) * 3 + j];
	s[i * 3 + j + 1] = tmp[i * 3 + j];
	s[(i + 1) * 3 + j] = tmp[(i + 1) * 3 + j + 1];
	s[(i + 1) * 3 + j + 1] = tmp[i * 3 + j + 1];
	return s;
}

string swapDec(string s, int i, int j) {
	string tmp = s;
	s[(i + 1) * 3 + j] = tmp[i * 3 + j];
	s[i * 3 + j] = tmp[i * 3 + j + 1];
	s[(i + 1) * 3 + j + 1] = tmp[(i + 1) * 3 + j];
	s[i * 3 + j + 1] = tmp[(i + 1) * 3 + j + 1];
	return s;
}
map<string, int> dep;

void bfs() {
	queue<string> q;
	dep["123456789"] = 0;
	q.push("123456789");
	while (!q.empty()) {
		string cur = q.front(); q.pop();
		if (dep[cur] >= 6)break;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				string child = swapIn(cur, i, j);
				if (dep.find(child) == dep.end()) {
					q.push(child);
					dep[child] = dep[cur] + 1;
				}
				child = swapDec(cur, i, j);
				if (dep.find(child) == dep.end()) {
					q.push(child);
					dep[child] = dep[cur] + 1;
				}
			}
	}
}

int solve(string s,int y) {
	queue<string> q; q.push(s);
	map<string, int> dep2;
	int mn = oo;
	while (!q.empty()) {
		string cur = q.front(); q.pop();
		if (dep.find(cur) != dep.end())
			mn = min(mn, dep[cur] + dep2[cur]);
		if (dep2[cur] >= y)continue;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				string child = swapIn(cur, i, j);
				if (dep2.find(child) == dep2.end()) {
					q.push(child);
					dep2[child] = dep2[cur] + 1;
				}
				child = swapDec(cur, i, j);
				if (dep2.find(child) == dep2.end()) {
					q.push(child);
					dep2[child] = dep2[cur] + 1;
				}
			}
	}
	return (mn == oo ? -1 : mn);
}
int main() {
	run();
	string s, xx(10, '0');
	int cnt = 0;
	bfs();
	while (cin >> s, xx != s) {
		int y = s[0] - '0';
		s = s.substr(1);
		cout << ++cnt << ". ";
		if (y <= 6) {
			if (dep.find(s) == dep.end() || dep[s] > y)
				cout << -1 << endl;
			else cout << dep[s] << endl;
		}
		else
			cout << solve(s, y - 6) << endl;
	}
}
