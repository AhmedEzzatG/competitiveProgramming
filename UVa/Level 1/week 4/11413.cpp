#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s,v) return cout<<s,v;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}
vector<int> v;
int n, m;
int lower(int s, int e, int x) {
	if (s > e) return -1;
	if (s == e) {
		if (v[s] <= x) return s;
		return -1;
	}
	int m = s + (e - s + 1) / 2;
	if (v[m] <= x) return lower(m, e, x);
	return lower(s, --m, x);
}
int check(int x) {
	int cnt = 0, ind = 0;
	while (ind < n) {
		ind = lower(ind + 1, n, v[ind] + x);
		if (ind == -1) return -1;
		cnt++;
	}
	return cnt;
}
int main() {
	Fast;
	file();
	while (cin >> n >> m) {
		v.resize(n + 2);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 2; i <= n; i++)
			v[i] += v[i - 1];
		int s = 1, e = v[n], mid, ca = 0;
		while (s <= e) {
			mid = (s + e) / 2;
			int cnt = check(mid);
			if (cnt == -1) s = mid + 1;
			else if (cnt > m) s = mid + 1;
			else ca = mid, e = mid - 1;
		}
		cout << ca << endl;
	}
}
