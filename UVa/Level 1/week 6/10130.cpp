#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);//freopen("output.out", "w", stdout);
#endif
}
int n;
vector<pair<int, int>> op;
map<pair<int, int>, int> mp;
int mxPrice(int w, int ind = 0) {
	if (ind >= n || w <= 0)return 0;
	if (mp.find({ w,ind }) != mp.end())
		return mp[{w, ind}];
	int mx = mxPrice(w, ind + 1);
	if (w >= op[ind].first) {
		mx = max(mx, op[ind].second +
			mxPrice(w - op[ind].first, ind + 1));
	}
	return mp[{w, ind}] = mx;
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		mp.clear();
		op.clear();
		cin >> n;
		op.resize(n);
		for (int i = 0; i < n; i++)
			cin >> op[i].second >> op[i].first;
		int g; cin >> g;
		vector<int> per(g);
		for (int i = 0; i < g; i++)
			cin >> per[i];
		int mx = 0;
		for (int i = 0; i < g; i++)
			mx += mxPrice(per[i]);
		cout << mx << endl;
	}
}
