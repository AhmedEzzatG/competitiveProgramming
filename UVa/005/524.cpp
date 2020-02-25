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
	freopen("input.in", "r", stdin);freopen("output.out", "w", stdout);
#endif
}

vector<bool> v;
vector<vector<int>> ans;
void Sieve(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 4; i <= n; i += 2) prime[i] = false;
	for (int i = 3; i * i <= n; i += 2) {
		if (prime[i])
			for (int j = i * i; j <= n; j += i + i)
				prime[j] = false;
	}
	v = prime;
}

void circle(int n, vector<int> c = { 1 }) {
	if (sz(c) == n) {
		if (v[c.back() + 1])ans.push_back(c);
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (find(all(c), i) == c.end()) {
			if (v[c.back() + i]) {
				c.push_back(i);
				circle(n, c);
				c.pop_back();
			}
		}
	}
}

int main() {
	run();
	int n, I = 1;
	while (cin >> n) {
		if (I > 1)cout << endl;
		cout << "Case " << I++ << ':' << endl;
		ans.clear();
		Sieve(n * n);
		circle(n);
		for (auto x : ans) {
			cout << 1;
			for (int i = 1; i < sz(x); i++)
				cout << ' ' << x[i];
			cout << endl;
		}
	}
}
