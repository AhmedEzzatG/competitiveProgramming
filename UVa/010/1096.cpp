#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
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

int n, s1, s2;
double mem[109][109][2][2];
vector<pair<int, int>> v;
vector<int> path[2];

double dis(pair<int, int> a, pair<int, int> b) {
	int xx = a.first - b.first, yy = a.second - b.second;
	return hypot(xx, yy);
}

int dcmp(double a, double b) {
	if (fabs(a - b) <= 1e-3)return 0;
	return (a < b ? -1 : 1);
}

double solve(int LR, int RL,bool take1,bool take2) {
	int idx = max(LR, RL) + 1;
	if (idx == n - 1) return dis(v.back(), v[LR]) + dis(v.back(), v[RL]);
	double& rt = mem[LR][RL][take1][take2];
	if (dcmp(rt, 0) != 0)return rt;
	if (idx == s1 || idx == s2) {
		rt = oo * oo;
		if (!take1) rt = min(rt, dis(v[LR], v[idx]) + solve(idx, RL, 1, take2));
		if (!take2) rt = min(rt, dis(v[RL], v[idx]) + solve(LR, idx, take1, 1));
	}
	else {
		rt = dis(v[LR], v[idx]) + solve(idx, RL, take1, take2);
		rt = min(rt, dis(v[RL], v[idx]) + solve(LR, idx, take1, take2));
	}
	return rt;
}

void build(int LR, int RL, bool take1, bool take2) {
	int idx = max(LR, RL) + 1;
	if (idx == n - 1) return;
	double rt = mem[LR][RL][take1][take2];
	if (idx == s1 || idx == s2) {
		double ch1 = oo * oo, ch2 = oo * oo;
		if (!take1) ch1 = dis(v[LR], v[idx]) + solve(idx, RL, 1, take2);
		if (!take2) ch2 = dis(v[RL], v[idx]) + solve(LR, idx, take1, 1);
		if (dcmp(rt, ch1) == 0) {
			path[0].push_back(idx);
			build(idx, RL, 1, take2);
		}
		else {
			path[1].push_back(idx);
			build(LR, idx, take1, 1);
		}
	}
	else {
		double ch1 = dis(v[LR], v[idx]) + solve(idx, RL, take1, take2);
		double ch2 = dis(v[RL], v[idx]) + solve(LR, idx, take1, take2);
		if (dcmp(rt, ch1) == 0) {
			path[0].push_back(idx);
			build(idx, RL, take1, take2);
		}
		else {
			path[1].push_back(idx);
			build(LR, idx, take1, take2);
		}
	}
}

int main() {
	run();
	int I = 0;
	while (cin >> n >> s1 >> s2, n || s1 || s2) {
		cout << "Case " << ++I << ": ";
		path[0].clear();
		path[1].clear();
		v.resize(n);
		for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
		clr(mem, 0);
		cout << fixed << setprecision(2) << solve(0, 0, 0, 0) << endl;
		build(0, 0, 0, 0);
		reverse(all(path[1]));
		cout << 0;
		for (auto it : path[0])cout << ' ' << it;
		cout << ' ' << n - 1;
		for (auto it : path[1])cout << ' ' << it;
		cout << " 0\n";
	}
}