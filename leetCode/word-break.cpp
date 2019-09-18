class Solution {
public:
	set<string> dictionary;
	vector<string> words;
	string word;
	vector<int> mem;
	int canSplit(int start) {
		if (start == word.size())return 1;
		int& rt = mem[start];
		if (~rt)return rt;
		rt = 0;
		string subWord;
		for (int end = start; end < word.size(); end++) {
			subWord += word[end];
			if (dictionary.find(subWord) != dictionary.end())
				rt |= canSplit(end + 1);
		}
		return rt;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		word = s;
		dictionary = set<string>(wordDict.begin(), wordDict.end());
		mem = vector<int>(word.size() + 1, -1);
		return canSplit(0);
	}
};
