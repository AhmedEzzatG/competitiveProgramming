#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;
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
	int n;
	ll k;
	cin >> n >> k;
	vector<int> v(n);
	ll st = 0, ed = 0, ans = 0;
	for (auto &it : v) {
		cin >> it;
		ed += it;
	}
	auto count_subarrays = [&](ll s) {
		ll sum = 0, cnt = 0;
		ordered_set<pair<ll, int>> st;
		st.insert( { 0, 0 });
		for (int i = 0; i < n; i++) {
			sum += v[i];
			cnt += sz(st) - st.order_of_key( { sum - s, -1 });
			st.insert( { sum, i + 1 });
		}
		return cnt;
	};
	while (st <= ed) {
		ll md = (st + ed >> 1);
		if (count_subarrays(md) < k)
			st = md + 1;
		else
			ed = md - 1, ans = md;
	}
	cout << ans << endl;
}
