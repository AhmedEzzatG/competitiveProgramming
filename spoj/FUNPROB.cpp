#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	cout << fixed << setprecision(6);
	int n, m;
	while (cin >> n >> m) {
		if (n == m && n == 0)
			return 0;
		if (n > m)
			cout << 0.0 << endl;
		else
			cout << (double) (m + 1 - n) / (m + 1) << endl;

	}
}
