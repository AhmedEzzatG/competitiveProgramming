class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();
		vector<int> dp(n + 1);
		dp[n] = 1;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '0')continue;
			dp[i] += dp[i + 1];
			if (s[i] == '1' && i + 1 < n)
				dp[i] += dp[i + 2];
			else if (s[i] == '2' && i + 1 < n && s[i + 1] <= '6')
				dp[i] += dp[i + 2];
		}
		return dp[0];
	}
};
