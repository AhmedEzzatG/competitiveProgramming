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
#define exit(s) return cout<<s,0;
#define watch(x) cout << (#x) << " = " << x << endl
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);
#endif
}
typedef pair<int, ll> pil;
int main() {
	Fast;
	file();
	string s;
	priority_queue<pil, vector<pil>, greater<pil>>pq;
	while (cin >> s) {
		if (s == "#")break;
		ll a, x; cin >> a >> x;
		for (int i = 1; i <= 10000; i++)
			pq.push({ i * x ,a });
	}
	int n; cin >> n;
	while (n--) {
		cout << pq.top().second << endl;
		pq.pop();
	}
}
