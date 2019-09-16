#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (ll)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v) return cout<<v,0
#define watch(x) cout << (#x) << " = " << x << endl
#define PI acos(-1)
#define EPS 1e-5
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}

vector<double> x;
string ans[]{ "up hill", "well diameter", "water level", "bucket volume",
		"bucket ascent rate", "down hill", "required volume", "TIME REQUIRED" };
string ans2[]{ "sec", "in", "in", "cu ft", "in/sec", "sec", "cu ft", "sec" };
int main() {
	run();
	cout << fixed << setprecision(2);
	double up, d, l, b, p, down, v;
	const double ac = 32.2 * 12;
	int I = 0;
	while (cin >> up) {
		if (up < 1)return 0;
		if (I)cout << endl;
		cout << "Scenario " << ++I << ":" << endl;
		cin >> d >> l >> b >> p >> down >> v;
		x.clear();
		x = { up,d,l,b,p,down,v };
		b *= 12 * 12 * 12;
		v *= 12 * 12 * 12;
		int cnt = ceil(v / b - EPS);
		double time = (up + down) * cnt;
		double h = 4 * b / (d * d * PI);
		while (cnt--) {
			time += sqrt(2 * l / ac);
			time += l / p;
			l += h;
		}
		x.push_back(time);
		for (int i = 0; i < 8; i++) {
			int sz = 26 - sz(ans[i]);
			cout << setw(5) << ' ';
			cout << ans[i];
			cout << setw(sz) << x[i];
			cout << ' ' << ans2[i] << endl;
		}
	}
}
