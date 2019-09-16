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
int m;
vector<int> v;
vector<int> out;
int mx = 0;
void maxTrack(int ind, int sum,vector<int> st) {
	if (sum > m)return;
	if (ind >= sz(v)) {
		if (sum > mx) mx = sum, out = st;
		if (sum == mx && sz(st) > sz(out))out = st;
		return;
	}
	maxTrack(ind + 1, sum, st);
	st.push_back(v[ind]);
	maxTrack(ind + 1, v[ind] + sum, st);
}
int main() {
	run();
	int n;
	while (cin >> m >> n) {
		v.resize(n);
		out.clear();
		mx = 0;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		maxTrack(0, 0, {});
		for (int x : out)
			cout << x << ' ';
		cout << "sum:" << mx << endl;
	}
}
