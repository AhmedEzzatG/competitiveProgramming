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
	freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);
#endif
}

int n, t;
vector<int> v;
set < vector<int>, greater<vector<int>>> out;
int mx = 0;
void dSum(int ind, int sum, vector<int> st) {
	if (sum > t)return;
	if (ind >= n) {
		if (sum == t) {
			sort(allr(st));
			out.insert(st);
		}
		return;
	}
	dSum(ind + 1, sum, st);
	st.push_back(v[ind]);
	dSum(ind + 1, sum + v[ind], st);
}

int main() {
	run();
	while (cin >> t >> n, (t || n)) {
		cout << "Sums of " << t << ':' << endl;
		v.resize(n);
		out.clear();
		mx = 0;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		dSum(0, 0, {});
		if (out.empty())cout << "NONE" << endl;
		for (auto x : out) {
			cout << x[0];
			for (int i = 1; i < sz(x); i++) {
				cout << '+' << x[i];
			}
			cout << endl;
		}
	}
}
