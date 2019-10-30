#define sz(v) (int)(v.size())
class Solution {
public:
	string x, y;
	bool valid(int i, int j) {
		return i < sz(x) && 0 <= j && (x[i] == y[j] || y[j] == '.');
	}
	bool isMatch(string s, string p) {
		x = s; y = p;
		vector<vector<int>> dp(sz(x) + 1, vector<int>(sz(y) + 1));
		dp[0][0] = 1;
		for (int i = 0; i <= sz(x); i++)
			for (int j = 0; j < sz(y); j++) {
				if (dp[i][j] == 0) continue;
				if (valid(i, j)) dp[i + 1][j + 1] |= dp[i][j];
				if (j + 1 < sz(y) && y[j + 1] == '*') {
					dp[i][j + 2] |= dp[i][j];
					if (valid(i, j))
						dp[i + 1][j] |= dp[i][j];
				}
				if (y[j] == '*') {
					dp[i][j + 1] |= dp[i][j];
					if (valid(i, j - 1))
						dp[i + 1][j] |= dp[i][j];
				}
			}
		return dp[sz(x)][sz(y)];
	}
};
