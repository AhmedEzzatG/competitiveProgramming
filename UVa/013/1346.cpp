#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
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
	int n;
	while (cin >> n) {
		vector<pair<int, pair<int, double>>>v(n);
		for (auto& a : v)cin >> a.first >> a.second.first >> a.second.second;
		sort(all(v),
			[](const pair<int, pair<int, double>>& a, const pair<int, pair<int, double>>& b) {
				double costAB = b.second.second * a.second.first,
					costBA = a.second.second * b.second.first;
				return costAB < costBA;
			});
		int k; cin >> k;
		cout << v[k - 1].first << endl;
	}
}