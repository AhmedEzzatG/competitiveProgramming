#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
vector<string> rotate(vector<string> &cur) {
	int n = sz(cur);
	vector<string> rt = cur;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			rt[j][n - i - 1] = cur[i][j];
	return rt;
}

int solve(vector<string> &cur, vector<string> &target) {
	for (int i = 0; i < 4; i++) {
		if (cur == target)
			return i;
		cur = rotate(cur);
	}
	return -1;
}
int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n) {
		cout << "Pattern " << ++I << " was ";
		vector<string> cur(n), target(n);
		for (int i = 0; i < n; i++)
			cin >> cur[i] >> target[i];
		int rt = solve(cur, target);
		if (rt == 0)
			cout << "preserved.\n";
		else if (~rt)
			cout << "rotated " << rt * 90 << " degrees.\n";
		else {
			for (int i = 0, j = n - 1; i < j; i++, j--)
				swap(cur[i], cur[j]);
			rt = solve(cur, target);
			if (rt == -1) {
				cout << "improperly transformed.\n";
				continue;
			}
			cout << "reflected vertically";
			if (rt == 0)
				cout << ".\n";
			else
				cout << " and rotated " << rt * 90 << " degrees.\n";
		}
	}
}