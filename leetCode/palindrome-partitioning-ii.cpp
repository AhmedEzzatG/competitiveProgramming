class Solution {
public:
	string s;
	vector<vector<int>> palindrome;
	vector<int> mem;
	int isPalindrome(int left, int right) {
		if (left > right)return 0;
		if (left == right || left + 1 == right)
			return s[left] == s[right];
		int& rt = palindrome[left][right];
		if (~rt)return rt;
		rt = 0;
		if (s[left] == s[right])
			rt = isPalindrome(left + 1, right - 1);
		return rt;
	}
	int palindromePartition(int start) {
		if (start == (int)(s.size()))return 0;
		int& rt = mem[start];
		if (~rt)return rt;
		rt = 0x3f3f3f3f;
		for (int end = start; end < (int)(s.size()); end++)
			if (isPalindrome(start, end))
				rt = min(rt, 1 + palindromePartition(end + 1));
		return rt;
	}
	int minCut(string s) {
		this->s = s;
		mem = vector<int>(s.size(), -1);
		palindrome = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
		return palindromePartition(0) - 1;
	}
};
