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

int main() {
	run();
	int T;
	cin >> T;
	for (int I = 1; I <= T; I++) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<ll> sum(n);
		for (int i = 1; i < n; i++) {
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}
		set<pair<ll, int>> st;
		st.insert( { 0, 0 });
		pair<int, int> ans = { 0, 0 };
		ll cur = 0;
		for (int j = 1; j < n; j++) {
			cur += v[j];
			st.insert( { cur, j });
			int i = st.begin()->second;
			if (sum[j] - sum[i] > sum[ans.second] - sum[ans.first])
				ans = { i, j };
			else if (sum[j] - sum[i] == sum[ans.second] - sum[ans.first]) {
				if (j - i > ans.second - ans.first)
					ans = { i, j };
				else if (j - i == ans.second - ans.first && i < ans.first)
					ans = { i, j };
			}
		}
		if (ans.first == ans.second)
			cout << "Route " << I << " has no nice parts\n";
		else {
			cout << "The nicest part of route " << I << " is between stops "
					<< ans.first + 1 << " and " << ans.second + 1 << endl;
		}
	}
}