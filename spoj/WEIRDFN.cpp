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
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	int t; cin >> t;
	while (t--) {
		priority_queue<int> lq;
		priority_queue<int, vector<int>, greater<int>> gq;
		lq.push(1);
		ll n, a, b, c;
		cin >> a >> b >> c >> n;
		ll sum = 1;
		for (int i = 2; i <= n; i++) {
			int md = lq.top();
			int cur = (((md * a) % mod) + ((i * b) % mod) + c) % mod;
			sum += cur;
			lq.push(cur);
			while (sz(lq) > sz(gq)) {
				cur = lq.top(); lq.pop();
				gq.push(cur);
			}
			if (sz(gq) > sz(lq)) {
				cur = gq.top(); gq.pop();
				lq.push(cur);
			}
		}
		cout << sum << endl;
	}
}
