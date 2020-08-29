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

string s;
vector<int> frq;
ll cntPerm() {
	long double rt = 1;
	int cnt = 1;
	for (int i = 0; i < sz(frq); i++)
		for (int j = 1; j <= frq[i]; j++) {
			rt *= cnt;
			rt /= j;
			cnt++;
		}
	return round(rt);
}

int main() {
	run();
	while (cin >> s, s != "#") {
		vector<char> v;
		for (auto &it : s)
			v.push_back(it);
		sort(all(v));
		v.resize(unique(all(v)) - v.begin());
		frq = vector<int>(v.size());
		for (auto &it : s) {
			it = lower_bound(all(v), it) - v.begin();
			frq[it]++;
		}
		ll rt = 1;
		for (int idx = 0; idx < sz(s); idx++) {
			for (int i = 0; i < s[idx]; i++)
				if (frq[i]) {
					frq[i]--;
					rt += cntPerm();
					frq[i]++;
				}
			frq[s[idx]]--;
		}
		cout << setw(10) << rt << endl;
	}
}