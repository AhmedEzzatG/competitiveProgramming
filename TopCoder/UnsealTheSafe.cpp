#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
class UnsealTheSafe {
public:
	UnsealTheSafe() {
		memset(mem, -1, sizeof(mem));
	}
	long long countPasswords(int N) {
		ll rt = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++)
				rt += solve(i, j, N - 1);
		return rt;
	}
private:
	vector<vector<int>> keypad =
			{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, { 0 } };
	bool valid(int i, int j) {
		return 0 <= i && i < sz(keypad) && 0 <= j && j < sz(keypad[i]);
	}
	ll mem[4][3][32];
	ll solve(int i, int j, int N) {
		if (!valid(i, j))
			return 0;
		if (N == 0)
			return 1;
		ll &rt = mem[i][j][N];
		if (~rt)
			return rt;
		rt = 0;
		for (int k = 0; k < 8; k += 2)
			rt += solve(i + dr[k], j + dc[k], N - 1);
		return rt;
	}
};
