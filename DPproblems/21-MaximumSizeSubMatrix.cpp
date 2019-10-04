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

const int MAX = 1001;
int mem[MAX][MAX];
vector<vi> v;
int sizeSubMatrix(int i, int j) {
	if (i < 0 || j < 0 || v[i][j] == 0) return 0;
	int& rt = mem[i][j];
	if (~rt) return rt;
	int up = sizeSubMatrix(i - 1, j);
	int left = sizeSubMatrix(i, j - 1);
	int commen = sizeSubMatrix(i - 1, j - 1);
	return rt = min({ up, left,commen }) + 1;
}


int main() {
	run();
	clr(mem, -1);
	int n; cin >> n;
	v = vector<vi>(n, vi(n));
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
		cin >> v[i][j];
	int mx = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		mx = max(mx, sizeSubMatrix(i, j));
		if (sizeSubMatrix(i, j) == 4)
			cout << i << ' ' << j << endl;
	}
	cout << mx << endl;
}
