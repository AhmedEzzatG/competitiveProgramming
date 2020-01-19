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

vector<ll> getDiv(ll n) {
	vector<ll> div;
	ll i = 1;
	for (; i * i < n; i++) {
		if (n % i == 0)
			div.push_back(i), div.push_back(n / i);
	}
	if (i * i == n)
		div.push_back(i);
	return div;
}
int main() {
	run();
	int k;
	while (cin >> k, k) {
		ll x = 1LL << k - 1, y = (1LL << k) - 1;
		vector<ll> divX = getDiv(x), divY = getDiv(y);
		set<ll> st;
		for (auto itX : divX)
			for (auto itY : divY)
				st.insert(itX * itY);
		ll sum = x * y;
		st.erase(sum);
		for (auto it : st)
			sum -= it;
		if (sum == 0) {
			cout << "Perfect: " << x * y << "!\n";
		} else {
			if (getDiv(k).size() == 2)
				cout << "Given number is prime. But, ";
			else
				cout << "Given number is NOT prime! ";
			cout << "NO perfect number is available.\n";
		}
	}

}
