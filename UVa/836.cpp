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
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}
const int N = 26;
vector<vector<int>> v;
int mem[N][N][N][N];
int size(int startX, int endX, int startY, int endY) {
	return (endX - startX + 1) * (endY - startY + 1);
}

bool valid(int startX, int endX, int startY, int endY) {
	int sum = v[endX][endY];
	sum -= v[startX - 1][endY];
	sum -= v[endX][startY - 1];
	sum += v[startX - 1][startY - 1];
	return sum == size(startX, endX, startY, endY);
}

int solve(int startX, int endX, int startY, int endY) {
	if (endX < startX || endY < startY)return 0;
	if (valid(startX, endX, startY, endY))
		return size(startX, endX, startY, endY);
	int& rt = mem[startX][endX][startY][endY];
	if (~rt)return rt;
	rt = 0;
	for (int i = startX; i <= endX; i++)  for (int j = startY; j <= endY; j++) {
		if (i == endX && j == endY)break;
		int ch = max(solve(startX, i, startY, j), solve(i + 1, endX, j + 1, endY));
		rt = max(rt, ch);
	}
	return rt;
}

int main() {
	run();
	int t; cin >> t;
	string tmp;
	cin.ignore();
	getline(cin, tmp);
	while (t--) {
		clr(mem, -1);
		vector<string> s;
		while (getline(cin, tmp), !tmp.empty())
			s.push_back(tmp);
		int n = sz(s);
		v = vector<vector<int>>(n + 1, vi(n + 1));
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++) {
			v[i][j] = s[i - 1][j - 1] - '0';
			v[i][j] += v[i - 1][j];
			v[i][j] += v[i][j - 1];
			v[i][j] -= v[i - 1][j - 1];
		}
		cout << solve(1, n, 1, n) << endl;
		if (t)cout << endl;
	}
}
