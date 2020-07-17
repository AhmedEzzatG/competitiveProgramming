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
	//freopen("input.out", "w", stdout);
#else
#endif
}

vector<pair<int,int>> v;
double dis(const pair<int, int>& a, const pair<int, int>& b) {
	double x = a.first - b.first, y = a.second - b.second;
	return hypot(x, y);
}

int n;
double mem[1 << 16];
double distances(int mask = 0) {
	if (mask == (1 << n) - 1)return 0;
	double& rt = mem[mask];
	if (rt >= 1e-9)return rt;
	rt = oo;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))continue;
		for (int j = 0; j < n; j++) {
			if (i == j || (mask & (1 << j)))continue;
			int nMask = mask | (1 << i) | (1 << j);
			rt = min(rt, dis(v[i], v[j]) + distances(nMask));
		}
	}
	return rt;
}


int main() {
	run();
	cout << fixed << setprecision(2);
	int I = 0;
	while (cin >> n, n) {
		n *= 2;
		clr(mem, -1);
		v = vector< pair<int, int>>(n);
		string s;
		for (int i = 0; i < n; i++)
			cin >> s >> v[i].first >> v[i].second;
		cout << "Case " << ++I << ": " << distances() << endl;
	}
}