class Solution {
public:
	string s;
	vector<vector<int>> palindrome;
	vector<vector<vector<string>>> build;
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
	void palindromePartition_allSolution(int start) {
		if (start == (int)(s.size()))return;
		vector<vector<string>>& rt = build[start];
		if ((int)(rt.size()))return;
		string cur = "";
		for (int end = start; end < (int)(s.size()); end++) {
			cur.push_back(s[end]);
			if (isPalindrome(start, end)) {
				if (end + 1 == s.size())
					rt.push_back(vector<string>(1, cur));
				else {
					palindromePartition_allSolution(end + 1);
					for (auto& it : build[end + 1]) {
						rt.push_back(vector<string>(1, cur));
						rt.back().insert(rt.back().end(), it.begin(), it.end());
					}
				}
			}
		}
	}
	vector<vector<string>> partition(string s) {
		this->s = s;
		palindrome = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
		build.resize(s.size() + 1);
		palindromePartition_allSolution(0);
		return build[0];
	}
};
