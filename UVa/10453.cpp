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

const int N = 1001;
int mem[N][N];
string s;
int solve(int i, int j) {
	if (j <= i)
		return 0;
	int &rt = mem[i][j];
	if (~rt)
		return rt;
	if (s[i] == s[j])
		return rt = solve(i + 1, j - 1);
	return rt = min(solve(i + 1, j), solve(i, j - 1)) + 1;
}

string build(int i, int j) {
	if (j < i)
		return "";
	if (i == j)
		return string(1, s[i]);
	if (s[i] == s[j])
		return s[i] + build(i + 1, j - 1) + s[j];
	if (solve(i + 1, j) < solve(i, j - 1)) {
		return s[i] + build(i + 1, j) + s[i];
	}
	return s[j] + build(i, j - 1) + s[j];
}
int main() {
	run();
	while (cin >> s) {
		memset(mem, -1, sizeof(mem));
		cout << solve(0, sz(s) - 1) << ' ' << build(0, sz(s) - 1) << endl;

	}
}
