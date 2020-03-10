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
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

bool in(char st, char ch, char ed) {
	return (st <= ch && ch <= ed);
}
vector<string> split(string s) {
	for (auto &ch : s)
		if (!in('A', ch, 'Z') && !in('a', ch, 'z') && !in('0', ch, '9'))
			ch = ' ';
	stringstream ss(s);
	vector < string > rt;
	while (ss >> s)
		rt.push_back(s);
	return rt;
}

vector<string> f, s;
vector<vector<int>> mem;
ll solve(int i, int j) {
	if (i == sz(f) || j == sz(s))
		return 0;
	int &rt = mem[i][j];
	if (~rt)
		return rt;
	if (f[i] == s[j])
		return rt = 1 + solve(i + 1, j + 1);
	return rt = max(solve(i + 1, j), solve(i, j + 1));
}
int main() {
	run();
	string x, y;
	int I = 0;
	while (getline(cin, x)) {
		getline(cin, y);
		cout << setw(2) << ++I;
		cout << ". ";
		f = split(x);
		s = split(y);
		if (f.empty() || s.empty()) {
			cout << "Blank!\n";
			continue;
		}
		mem = vector<vector<int>>(f.size(), vector<int>(s.size(), -1));
		cout << "Length of longest match: " << solve(0, 0) << endl;

	}
}
