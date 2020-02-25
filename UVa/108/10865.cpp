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
const ll oo = LLONG_MAX, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-4;
int dr[]{ -1, 1, 0, 0, 1, 1, -1, -1 };
int dc[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
#ifdef ONLINE_JUDGE
#endif
}
typedef complex<int> point;
#define X real()
#define Y imag()
int main() {
	run();
	int n;
	while (cin >> n, n) {
		vector<point> v(n);
		point mid;
		for (int i = 0; i < n; i++) {
			int x, y; cin >> x >> y;
			v[i] = { x,y };
			if (i == n / 2)
				mid = { x,y };
		}
		int cnt[2][2];
		clr(cnt, 0);
		for (int i = 0; i < n; i++) {
			if (v[i].X == mid.X || v[i].Y == mid.Y)
				continue;
			cnt[v[i].X > mid.X][v[i].Y > mid.Y]++;
		}
		cout << cnt[0][0] + cnt[1][1] << ' '
			<< cnt[1][0] + cnt[0][1] << endl;
	}
}
