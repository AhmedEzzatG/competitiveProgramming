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
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
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

long double calc(double ab, double ac, double ad, double bc, double bd,
		double cd) {
	long double w = ab, v = ac, u = ad, U = bc, V = bd, W = cd;
	long double X = (w - U + v) * (U + v + w);
	long double x = (U - v + w) * (v - w + U);
	long double Y = (u - V + w) * (V + w + u);
	long double y = (V - w + u) * (w - u + V);
	long double Z = (v - W + u) * (W + u + v);
	long double z = (W - u + v) * (u - v + W);
	long double a = sqrt(x * Y * Z);
	long double b = sqrt(X * y * Z);
	long double c = sqrt(X * Y * z);
	long double d = sqrt(x * y * z);
	long double volume = -a + b + c + d;
	volume *= a - b + c + d;
	volume *= a + b - c + d;
	volume *= a + b + c - d;
	volume = sqrt(volume) / (192.0 * u * v * w);
	return volume;
}

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int ab, ac, ad, bc, bd, cd;
		cin >> ab >> ac >> ad >> bc >> bd >> cd;
		cout << fixed << setprecision(4) << calc(ab, ac, ad, bc, bd, cd)
				<< endl;
	}
}
