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
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
int n;
double a;

const double EPS = 1e-6;
int dcmp(double x, double y) { return (fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1); }

double f(double h2) {
	double prev = a, cur = h2, nxt;
	for (int i = 2; i < n; i++) {
		nxt = 2 * cur + 2 - prev;
		if (dcmp(nxt, 0.0) <= 0)return -1;
		prev = cur;
		cur = nxt;
	}
	return cur;
}

double bs() {
	double st = 0, ed = a, md, ans = a;
	while (dcmp(st, ed) <= 0) {
		md = st + (ed - st) / 2.0;
		if (dcmp(f(md), 0.0) >= 0) ed = md - EPS, ans = md;
		else st = md + EPS;
	}
	return f(ans);
}

int main() {
	run();
	cout << fixed << setprecision(2);
	while (cin >> n >> a) {
		cout << bs() << endl;
	}
}