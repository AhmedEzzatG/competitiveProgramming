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
const int oo = INT_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-1;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	int n;
	while (cin >> n, n) {
		int ans = -1;double mx = -oo;
		for (int i = 0; i < n; i++) {
			double x, y; cin >> x >> y;
			if (x < y)swap(x, y);
			double size = max(min(x / 4, y), y / 2);
			if (mx < size)
				mx = size, ans = i + 1;
		}
		cout << ans << endl;
	}
}
