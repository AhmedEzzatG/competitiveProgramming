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

int mem[26][16 * 12 + 1], n;
vector<int> f, t, d, out;
void read(vector<int> &v, int n) {
	v = vector<int>(n);
	for (auto &it : v)
		cin >> it;
}

int solve(int idx, int h) {
	if (h < 0)
		return -oo;
	if (h == 0)
		return 0;
	if (idx == n)
		return -oo;
	int &rt = mem[idx][h];
	if (~rt)
		return rt;
	rt = 0;
	int cur = f[idx], sum = 0;
	for (int time = 0; time <= h; time++) {
		if (time == h)
			rt = max(rt, sum);
		if (h - time - t[idx] >= 0)
			rt = max(rt, sum + solve(idx + 1, h - time - t[idx]));
		sum += cur;
		cur = max(0, cur - d[idx]);
	}
	return rt;
}

void build(int idx, int h) {
	if (h <= 0 && idx == n)
		return;
	int best = solve(idx, h);
	int timeOfBest = 0;
	int cur = f[idx], sum = 0;
	for (int time = 0; time <= h; time++) {
		if (time == h && best == sum) {
			out[idx] = time * 5;
			return;
		}
		if (best == sum + solve(idx + 1, h - time - t[idx])) {
			timeOfBest = h - time - t[idx];
			out[idx] = time * 5;
		}
		sum += cur;
		cur = max(0, cur - d[idx]);
	}
	build(idx + 1, timeOfBest);
}

int main() {
	run();
	bool b = 0;
	while (cin >> n, n) {
		if (b)
			cout << endl;
		else
			b = 1;
		memset(mem, -1, sizeof(mem));
		out = vector<int>(n);
		int h;
		cin >> h;
		h *= 12;
		read(f, n);
		read(d, n);
		read(t, n - 1);
		t.push_back(0);
		build(0, h);
		cout << out[0];
		for (int i = 1; i < n; i++)
			cout << ", " << out[i];
		cout << "\nNumber of fish expected: " << solve(0, h) << endl;
	}
}
