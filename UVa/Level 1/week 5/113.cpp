#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define sz(s) (int)(s.size())
#define all(s) s.begin(),s.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x) << " = " << x << endl
#define numOfDigit(x) 1+(int)log10(x)
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);//freopen("out.txt", "w", stdout);
#endif
}
const int MAX = 1800;

vector<ll> v(MAX);

void reset0() {
	for (int i = 0; i < MAX; i++)v[i] = 0;
}

void reset() {
	for (int i = 0; i < MAX; i++) {
		if (v[i] > 9) {
			v[i + 1] += v[i] / 10;
			v[i] %= 10;
		}
	}
}

int lastDigit() {
	int l = MAX - 1;
	while (v[l] == 0 && l > 0)l--;
	return l;
}

void mul(ll x) {
	int l = lastDigit();
	for (int i = 0; i <= l; i++)
		v[i] *= x;
	reset();
}

string ToString() {
	reset();
	int l = lastDigit();
	string s;
	for (int i = 0; i <= l; i++)
		s.push_back(char('0' + v[i]));
	reverse(all(s));
	return s;
}

int ok(ll mid, int n, string s) {
	reset0();
	v[0] = 1;
	while (n--) mul(mid);
	string x = ToString();
	if (sz(x) == sz(s)) {
		if (x == s)return 0;
		return x > s ? 1 : -1;
	}
	return sz(x) > sz(s) ? 1 : -1;
}

int main() {
	Fast;
	file();
	int n; string s;
	while (cin >> n) {
		cin >> s;
		ll st = 1, ed = 1e9, mid, ans;
		while (st <= ed) {
			mid = (st + ed) / 2;
			int b = ok(mid, n, s);
			if (b == 1) ed = mid - 1;
			else if (b == 0) {
				ans = mid; break;
			}
			else st = mid + 1;
		}
		cout << ans << endl;
	}
}
