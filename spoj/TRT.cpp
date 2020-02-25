#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
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

vector<int> v;
int mem[2009][2009];
int solve(int i, int j) {
	if (j < i)return 0;
	int& rt = mem[i][j];
	if (~rt)return rt;
	int a = i + sz(v) - j;
	return rt = max(a * v[i] + solve(i + 1, j),
		a * v[j] + solve(i, j - 1));
}

int main() {
	run();
	clr(mem, -1);
	int n; cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	cout << solve(0, sz(v) - 1) << endl;
}
