#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

vector<pair<int, int>> items;
vector<vector<int>> mem;
int knapsack01(int index, int weight) {
	if (weight <= 0 || index == sz(items))return 0;
	int& rt = mem[index][weight];
	if (~rt)return rt;
	rt = knapsack01(index + 1, weight);
	rt = max(rt, knapsack01(index + 1, weight - items[index].first) + items[index].second);
	return rt;
}

int main() {
	run();
	int n, w;
	cin >> n >> w;
	items.resize(n);
	for (auto& it : items)cin >> it.first >> it.second;
	mem = vector<vector<int>>(n, vector<int>(w + 1, -1));
	cout << knapsack01(0, w);
}
