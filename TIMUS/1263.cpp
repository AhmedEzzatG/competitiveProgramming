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
#define oo 0x3f3f3f3fLL
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int main() {
	run();
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n + 1);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	cout << fixed << setprecision(2);
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] * 100.0 / m  << "%" << endl;
	}
}