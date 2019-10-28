class Solution {
public:
	vector<int> v;
	vector<vector<int>> mem;
	int solve(int left, int right) {
		int& rt = mem[left][right];
		if (~rt)return rt;
		rt = 0;
		for (int i = left + 1; i < right; i++) {
			int cur = v[i] * v[left] * v[right] + solve(left, i) + solve(i, right);
			rt = max(rt, cur);
		}
		return rt;
	}
	int maxCoins(vector<int>& nums) {
		v.push_back(1);
		v.insert(v.end(), nums.begin(), nums.end());
		v.push_back(1);
		mem = vector<vector<int>>(v.size(), vector<int>(v.size(), -1));
		return solve(0, v.size() - 1);
	}
};
