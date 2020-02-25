#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
/*
template<typename T> vector<T> create(size_t n) { return vector<T>(n); }
template<typename T, typename... Args>
auto create(size_t n, Args... args) { return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
*/
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}

vector<vector<ll>> v;
vector<vector<bool>> vis;
vector<vector<string>> s;

ll to_integer(string s) {
	stringstream ss(s);
	ll x; ss >> x;
	return x;
}

vector<string> split(string s) {
	for (char& ch : s)
		if (ch == '+')
			ch = ' ';
	stringstream ss(s);
	vector<string> rt;
	while (ss >> s)rt.push_back(s);
	return rt;
}

ll solve(int i, int j);

ll get_cell(string s) {
	int row = 0, col = 0;
	for (auto ch : s)
		if ('0' <= ch && ch <= '9')
			row = row * 10 + ch - '0';
		else
			col = col * 26 + ch - 'A' + 1;
	return solve(row - 1, col - 1);
}

ll solve(int i, int j) {
	ll& rt = v[i][j];
	if (vis[i][j])
		return rt;
	vis[i][j] = 1;
	rt = 0;
	if (s[i][j][0] != '=')
		return rt = to_integer(s[i][j]);
	s[i][j].erase(s[i][j].begin());
	vector<string> tmp = split(s[i][j]);
	for (string it : tmp)
		rt += get_cell(it);
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		s = vector<vector<string>>(n,vector<string>(m));
		v = vector<vector<ll>>(n, vector<ll>(m));
		vis = vector<vector<bool>>(n, vector<bool>(m));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			cin >> s[i][j];
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
			cout << solve(i, j) << " \n"[j + 1 == m];
	}
}
