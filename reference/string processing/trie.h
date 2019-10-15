#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> trie;
vector<bool> leaf;
void addNode() {
	trie.push_back(vector<int>(26, -1));
	leaf.push_back(false);
}

void insert(const string& s) {
	int root = 0;
	for (const char& ch : s) {
		if (trie[root][ch - 'a'] == -1) {
			trie[root][ch - 'a'] = trie.size();
			addNode();
		}
		root = trie[root][ch - 'a'];
	}
	leaf[root] = true;
}

bool find(const string& s) {
	int root = 0;
	for (const char& ch : s) {
		if (trie[root][ch - 'a'] == -1)
			return false;
		root = trie[root][ch - 'a'];
	}
	return leaf[root];
}

struct trie {
	map<char, trie*> nxt;
	bool isLeaf;
	trie() { isLeaf = 0; }
	void insert(char* str) {
		if (*str == '\0') { isLeaf = true; return; }
		char cur = *str;
		if (nxt.find(cur) == nxt.end())
			nxt[cur] = new trie();
		nxt[cur]->insert(++str);
	}
	bool find(char* str) {
		if (*str == '\0') { return isLeaf; }
		char cur = *str;
		if (nxt.find(cur) == nxt.end())
			return false;
		return nxt[cur]->find(++str);
	}
	bool prefixExist(char* str) {
		if (*str == '\0') { return true; }
		char cur = *str;
		if (nxt.find(cur) == nxt.end())
			return false;
		return nxt[cur]->prefixExist(++str);
	}
};