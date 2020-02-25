#include<bits/stdc++.h>
using namespace std;

int n, c;
vector<int> v;
bool ok(int dis) {
	int last = v[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (v[i] - last >= dis) {
			last = v[i];
			cnt++;
		}
	}
	return cnt >= c;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> c;
		v = vector<int>(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int st = 1, ed = 1e9, md, ans = -1;
		while (st <= ed) {
			md = st + ed >> 1;
			if (ok(md))
				st = md + 1, ans = md;
			else ed = md - 1;
		}
		cout << ans << endl;
	}
}
