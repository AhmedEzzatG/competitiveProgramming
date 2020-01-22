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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	const int mod = 34943;
	string s;
	while (getline(cin, s),s != "#") {
		ll sum = 0;
		for (auto ch : s)
			sum = ((sum << 8) + ch) % mod;
		sum = (sum << 16) % mod;
		sum = (mod - sum) % mod;
		string hex(5,' ');
		for (int i = 4; i >= 0; i--) {
			if (i == 2)continue;
			int r = sum % 16;
			if (0 <= r && r < 10)
				hex[i] = r + '0';
			else hex[i] = r - 10 + 'A';
			sum /= 16;
		}
		cout << hex << endl;
	}

}