class Solution {
	vector<int> v, mem;
	int maxSum(int index) {
		if (index >= v.size())return 0;
		int& rt = mem[index];
		if (~rt)return rt;
		rt = maxSum(index + 1);
		rt = max(rt, v[index] + maxSum(index + 2));
		return rt;
	}
public:
	int rob(vector<int>& nums) {
		v = nums;
		mem = vector<int>(nums.size(), -1);
		return maxSum(0);
	}
};
