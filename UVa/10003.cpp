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
	//freopen("input.out", "w", stdout);
#else
#endif
}
int l, n;
vector<int> point;
int mem[59][59];
int cut(int i, int j) {
	if (j < i)return 0;
	int s = point[i - 1], e = point[j + 1];
	if (j == i)return e - s;
	int& rt = mem[i][j];
	if (~rt)return rt;
	rt = oo;
	int cost = e - s;
	for (int k = i; k <= j; k++)
		rt = min(rt, cut(i, k - 1) + cut(k + 1, j));
	return rt += cost;
}

int main() {
	run();
	while (cin >> l, l) {
		clr(mem, -1);
		cin >> n;
		point = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) cin >> point[i];
		point.push_back(l);
		cout << "The minimum cutting is " << cut(1, n) << "." << endl;
	}
}
