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
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
int cnt = 0;
vector<int> temp;
void merge(vi& v, int s, int m, int e) {
	for (int i = s; i <= e; i++) temp[i] = v[i];
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e)
		if (temp[i] <= temp[j]) v[k++] = temp[i++];
		else  v[k++] = temp[j++], cnt += j - k;
	while (i <= m)v[k++] = temp[i++];
	while (j <= e)v[k++] = temp[j++];
}

void merge_sort(vi & v, int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2;
	merge_sort(v, s, m);
	merge_sort(v, m + 1, e);
	merge(v, s, m, e);
}

int main() {
	Fast;
	file();
	int n;
	while (cin >> n, n) {
		temp.resize(n);
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cnt = 0;
		merge_sort(v, 0, n - 1);
		cout << ((cnt & 1) ? "Marcelo" : "Carlos") << endl;
	}
}
