#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
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
int main() {
	run();
	double cows, cars, nshow;
	while (cin >> cows >> cars >> nshow) {
		double p = (cows / (cows + cars)) * (cars / (cows - nshow + cars - 1));
		double p2 = (cars / (cows + cars)) * ((cars - 1) / (cows - nshow + cars - 1));
		cout << fixed << setprecision(5) << p + p2 << endl;
	}
}