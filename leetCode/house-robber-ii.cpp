class Solution {
	vector<int> v;
	vector<vector<int>> mem;
	int maxSumCycle(int index, bool takeFirst) {
		if (index >= v.size())return 0;
		int& rt = mem[index][takeFirst];
		if (~rt)return rt;
		rt = maxSumCycle(index + 1, takeFirst);
		if (index + 1 != v.size() || !takeFirst)
			rt = max(rt, v[index] + maxSumCycle(index + 2, takeFirst));
		return rt;
	}
public:
	int rob(vector<int>& nums) {
		if (nums.empty())return 0;
		v = nums;
		mem = vector<vector<int>>(nums.size(), { -1,-1 });
		return max(maxSumCycle(1, 0), maxSumCycle(2, 1) + v[0]);
	}
};
