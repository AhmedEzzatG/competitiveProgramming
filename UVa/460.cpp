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
	freopen("input.in", "r", stdin); //freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int xl, yd, xr, yu, x1, y1, x2, y2;
		cin >> xl >> yd >> xr >> yu >> x1 >> y1 >> x2 >> y2;
		xl = max(xl, x1); yd = max(yd, y1);
		xr = min(xr, x2); yu = min(yu, y2);
		if (yu <= yd || xr <= xl)cout << "No Overlap";
		else cout << xl << ' ' << yd << ' ' << xr << ' ' << yu;
		cout << endl;
		if (t) cout << endl;
	}
}
