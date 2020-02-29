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
int intersections_volume(vector<int> a, vector<int> b) {
	int ans = 1;
	for (int i = 0; i < 3; i++) {
		int stA = a[i], edA = a[i] + a[3];
		int stB = b[i], edB = b[i] + b[3];
		ans *= max(0, min(edA, edB) - max(stA, stB));
	}
	return ans;
}

int main() {
	run();
	int n;
	while (cin >> n, n) {
		vector<vector<int>> v(n, vector<int>(4));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				cin >> v[i][j];

		ll ans = 1;
		for (int j = 0; j < 3; j++) {
			int mn = oo, mx = 0;
			for (int i = 0; i < n; i++)
				mn = min(mn, v[i][j] + v[i][3]), mx = max(mx, v[i][j]);
			ans *= max(0, mn - mx);
		}
		cout << ans << endl;
	}

}
