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
int n, k;
ll mem[201][31];
vector<ll> v;
pair<int, ll> getMin(int start, int end) {
	pair<int, ll> rt;
	ll cost = 0;
	for (int j = start; j <= end; j++)
		cost += v[j] - v[start];
	rt = { start, cost };
	for (int cur = start + 1; cur <= end; cur++) {
		cost += (cur - start) * (v[cur] - v[cur - 1]);
		cost -= (end - cur + 1) * (v[cur] - v[cur - 1]);
		if (cost < rt.second)
			rt = { cur, cost };
	}
	return rt;
}

ll solve(int start, int cnt) {
	if (start == n)
		return 0;
	if (cnt == k)
		return INF;
	ll &rt = mem[start][cnt];
	if (rt < INF)
		return rt;
	for (int end = start; end < n; end++) {
		pair<int, ll> p = getMin(start, end);
		rt = min(rt, p.second + solve(end + 1, cnt + 1));
	}
	return rt;
}

void build(int start, int cnt) {
	if (start == n)
		return;
	ll best = solve(start, cnt);
	++cnt;
	for (int end = start; end < n; end++) {
		pair<int, ll> p = getMin(start, end);
		if (best == p.second + solve(end + 1, cnt)) {
			cout << "Depot " << cnt << " at restaurant " << p.first + 1
					<< " serves restaurant";
			if (end > start)
				cout << "s " << start + 1 << " to " << end + 1 << endl;
			else
				cout << " " << start + 1 << endl;
			build(end + 1, cnt);
			return;
		}
	}
}

int main() {
	run();
	int I = 1;
	while (cin >> n >> k, n || k) {
		cout << "Chain " << I++ << endl;
		memset(mem, oo, sizeof(mem));
		v = vector<ll>(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		build(0, 0);
		cout << "Total distance sum = " << solve(0, 0) << endl << endl;
	}
}
