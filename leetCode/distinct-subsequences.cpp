class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.size(), m = t.size();
		vector<long long> dp(m + 1);
		dp[m] = 1;
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < m; j++)
				if (s[i] == t[j]) dp[j] += dp[j + 1];
		return dp[0];
	}
};
