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
vector<int> v;
int mxSub(int ind, int last) {
	if (ind >= n)return 0;
	int c = mxSub(ind + 1, last);
	if (v[ind] > last) {
		c = max(c, 1 + mxSub(ind + 1, v[ind]));
	}
	return c;
}

int main() {
	run();
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << mxSub(0, 0);
}
