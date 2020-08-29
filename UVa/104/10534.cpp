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

vector<int> LIS(const vector<int> &v) {
	int n = sz(v);
	vector<int> rt(n), lis(n);
	int l = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.begin() + l, v[i]) - lis.begin();
		if (idx == l)
			l++;
		rt[i] = idx + 1;
		lis[idx] = v[i];
	}
	return rt;
}
int main() {
	run();
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (auto &it : v)
			cin >> it;
		vector<int> lis = LIS(v);
		reverse(all(v));
		vector<int> lds = LIS(v);
		reverse(all(lds));
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, 2 * min(lis[i], lds[i]) - 1);
		cout << ans << endl;
	}
}