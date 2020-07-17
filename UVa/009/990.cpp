#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}

int n, w;
vector<int> d, v, out;
int mem[39][1009];
int solve(int idx, int time) {
	if (time < 0)return -oo;
	if (idx == n)return 0;
	int& rt = mem[idx][time];
	if (~rt)return rt;
	rt = solve(idx + 1, time);
	rt = max(rt, v[idx] + solve(idx + 1, time - 3 * w * d[idx]));
	return rt;
}


void build(int idx, int time) {
	if (time < 0)return;
	if (idx == n)return;
	int rt = mem[idx][time];
	int ch1 = solve(idx + 1, time);
	int ch2 = v[idx] + solve(idx + 1, time - 3 * w * d[idx]);
	if (rt == ch2) {
		out.push_back(idx);
		build(idx + 1, time - 3 * w * d[idx]);
	}
	else build(idx + 1, time);
}

int main() {
	run();
	int t;
	bool b = 0;
	while (cin >> t) {
		if (b)cout << endl;
		else b = 1;
		cin >> w >> n;
		v = d = vector<int>(n);
		clr(mem, -1);
		out = vector<int>();
		for (int i = 0; i < n; i++)
			cin >> d[i] >> v[i];
		cout << solve(0, t) << endl;
		build(0, t);
		cout << sz(out) << endl;
		for (auto i : out)
			cout << d[i] << ' ' << v[i] << endl;
	}
}