class Solution {
public:
	set<string> dictionary;
	vector<vector<string>> build;
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

	void breakWord(int start = 0) {
		if (start == word.size())return;
		vector<string>& rt = build[start];
		if (!rt.empty())return;
		string subWord;
		for (int end = start; end < word.size(); end++) {
			subWord += word[end];
			if (dictionary.find(subWord) != dictionary.end() && canSplit(end + 1)) {
				if (end + 1 < word.size()) {
					breakWord(end + 1);
					vector<string> tmp = build[end + 1];
					for (auto& it : tmp) it = subWord + ' ' + it;
					rt.insert(rt.end(), tmp.begin(), tmp.end());
				}
				else rt.push_back(subWord);
			}
		}
	}

	vector<string> wordBreak(string s, vector<string>& wordDict) {
		word = s;
		dictionary = set<string>(wordDict.begin(), wordDict.end());
		mem = vector<int>(word.size() + 1, -1);
		build = vector<vector<string>>(word.size() + 1);
		build[word.size()] = { "" };
		breakWord();
		return build[0];
	}
};
