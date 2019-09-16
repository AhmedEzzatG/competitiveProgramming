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
#define oo ll(2e10)
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);
#endif
}
string x, y;
map<pair<int, int>, int> mp;
bool valid(int i, int j) { return i < sz(x) && j < sz(y); }
int mxSub(int i = 0, int j = 0) {
	if (!valid(i, j))return 0;
	if (mp.find({ i,j }) != mp.end()) return mp[{i, j}];
	if (x[i] == y[j])
		return  mp[{i, j}] = 1 + mxSub(i + 1, j + 1);
	int mx = mxSub(i + 1, j);
	mx = max(mx, mxSub(i, j + 1));
	return mp[{i, j}] = mx;
}

int main() {
	run();
	int I = 0;
	while (getline(cin, x)) {
		if (x == "#")return 0;
		mp.clear();
		cout << "Case #" << ++I <<
			": you can visit at most ";
		getline(cin, y);
		cout << mxSub() << " cities." << endl;
	}
}
