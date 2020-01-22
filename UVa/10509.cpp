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
template<typename T, int val>
vector<T> create(size_t n) {
	return vector<T>(n, val);
}
template<typename T, int val, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T,val>(args...))>(n, create<T, val>(args...));
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

int main(){
	run();
	double n;
	while(cin >> n,n > 1e-9){
		int i = pow(n + 1e-6,1.0/3);
		double dx = (n - i*i*i)/(3*i*i);
		cout << fixed << setprecision(4) << i+dx << endl;
	}
}