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
typedef vector<vector<int>> matrix;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int MAX = 1001;
ll mem[MAX][4][3];
vector<vector<int>> v;
bool valid(int i, int j) {
	return 0 <= i && i < 4 && 0 <= j && j < 3 && v[i][j] != -1;
}

ll solve(int i, int j, int k) {
	if (!valid(i, j))return 0;
	if (k == 0)return 1;
	ll& rt = mem[k][i][j];
	if (~rt)return rt;
	rt = solve(i, j, k - 1);
	for (int l = 0; l < 8; l += 2)
		rt += solve(i + dr[l], j + dc[l], k - 1);
	return rt;
}

int main() {
	run();
	clr(mem, -1);
	v = { {1,2,3},
	      {4,5,6},
		  {7,8,9},
		  {-1,0,-1}};
	for (int k = 1; k <= 10; k++) {
		ll rt = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
				rt += solve(i, j, k - 1);
		cout << rt << endl;
	}
}
