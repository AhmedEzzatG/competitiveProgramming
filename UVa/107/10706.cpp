#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

ll number_of_digits(ll k) {
	ll sum = 0, last = 0, cnt_digit = 1;
	while (last < k) {
		sum += cnt_digit * (min(k, last * 10 + 9) - last);
		last = (last * 10 + 9);
		cnt_digit++;
	}
	return sum;
}

int main() {
	run();
	vector<ll> num = { 0 };
	for (int i = 1;; i++) {
		num.push_back(num.back() + number_of_digits(i));
		if (num.back() > INT_MAX)
			break;
	}
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		x--;
		int k = upper_bound(all(num), x) - num.begin();
		x -= num[k - 1];
		int st = 1, ed = k, ans = 0;
		while (st <= ed) {
			int md = st + ed >> 1;
			if (number_of_digits(md) <= x)
				st = md + 1, ans = md;
			else
				ed = md - 1;
		}
		x -= number_of_digits(ans);
		cout << to_string(ans + 1)[x] << endl;
	}
}