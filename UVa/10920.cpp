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

int main() {
	run();
	int sz, p;
	while (cin >> sz >> p, sz || p) {
		int cnt = 1;
		pair<int, int> pos;
		pos.first = pos.second = (sz + 1) / 2;
		while (cnt * cnt <= p)
			cnt += 2;
		cnt -= 2;
		pos.first -= cnt / 2;
		pos.second += cnt / 2;
		int cur = cnt * cnt;
		if (cur < p) {
			cur++;
			pos.first--;
		}
		for (int k = 6; k >= 0 && cur < p; k -= 2) {
			for (int i = (k == 6); i <= cnt && cur < p; i++) {
				cur++;
				pos.first += dr[k];
				pos.second += dc[k];
			}
		}
		cout << "Line = " << sz - pos.first + 1 << ", column = " << pos.second << ".\n";

	}
}
