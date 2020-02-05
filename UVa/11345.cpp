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
const double PI = acos(-1), EPS = 1e-4;
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
	int t; cin >> t;
	for (int I = 1; I <= t; I++) {
		int n; cin >> n;
		int x, xx, y, yy;
		cin >> x >> y >> xx >> yy; n--;
		while (n--) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x = max(x, x1);
			y = max(y, y1);
			xx = min(xx, x2);
			yy = min(yy, y2);
		}
		cout << "Case " << I << ": ";
		if (yy < y || xx < x)cout << 0;
		else cout << (xx - x) * (yy - y);
		cout << endl;
	}
}
