#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define clr(v,val) memset(v,val,sizeof(v))
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v,val) return cout<<v,val
#define watch(x) cout << (#x) << " = " << x << endl
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };

void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);//freopen("output.out", "w", stdout);
#endif
}
vector<int> divisors(int n) {
	vector<int> v; int i = 1;
	for (; i * i < n; i++)
		if (!(n % i)) {
			v.push_back(i), v.push_back(n / i);
			v.push_back(-1 * i), v.push_back(-1 * n / i);
		}
	if (i* i == n) v.push_back(i), v.push_back(-1 * i);
	sort(all(v));
	return v;
}
int a, b, c;
bool valid(ll x, ll y, ll z) {
	if ((x* y* z == b) && (x + y + z == a)) {
		x *= x, y *= y, z *= z;
		return (x + y + z == c);
	}
	return false;
}

int main() {
	run();
	int n;
	while (cin >> n) {
		while (n--) {
			cin >> a >> b >> c;
			ll x, y, z;
			bool get = 0;
			vector<int> v = divisors(b);
			for (int i = 0; i < sz(v); i++) {
				for (int j = i + 1; j < sz(v); j++) {
					for (int k = j + 1; k < sz(v); k++) {
						x = v[i], y = v[j], z = v[k];
						if (valid(x, y, z)) {
							get = 1;
							i = j = k = sz(v);
							break;
						}
					}
				}
			}
			if (get)cout << x << ' ' << y << ' ' << z;
			else cout << "No solution.";
			cout << endl;
		}
	}
}
