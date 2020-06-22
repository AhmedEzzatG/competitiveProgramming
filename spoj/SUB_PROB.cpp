#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifdef EZZAT
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

int nextNodeId;
struct aho_corasick {
	struct trie_node {
		map<char, trie_node*> nxt;
		vector<int> patternsIdxs;
		trie_node *fail;
		int id;
		trie_node() {
			fail = NULL;
			id = nextNodeId++;
		}
		void insert(const char *str, int patternIdx) {
			if (*str == '\0') {
				patternsIdxs.push_back(patternIdx);
				return;
			}
			if (nxt.find(*str) == nxt.end())
				nxt[*str] = new trie_node();
			nxt[*str]->insert(++str, patternIdx);
		}
	};
	trie_node *root;
	vector<string> patterns;
	aho_corasick(const vector<string> &_patterns) {
		nextNodeId = 0;
		patterns = _patterns;
		root = new trie_node();
		for (int i = 0; i < patterns.size(); i++)
			root->insert(patterns[i].c_str(), i);
		buildAhoTree();
	}

	void fail(trie_node *&cur, char ch) {
		while (cur->id != 0 && !cur->nxt.count(ch))
			cur = cur->fail;
		if (cur->nxt.count(ch))
			cur = cur->nxt[ch];
		else
			cur = root;
	}
	void buildAhoTree() {
		queue<trie_node*> q;
		for (auto &child : root->nxt) {
			q.push(child.second);
			child.second->fail = root;
		}
		while (!q.empty()) {
			trie_node *cur = q.front();
			q.pop();
			for (auto &child : cur->nxt) {
				trie_node *k = cur->fail;
				fail(k, child.first);
				child.second->fail = k;
				vector<int> &idxs = child.second->patternsIdxs;
				idxs.insert(idxs.end(), k->patternsIdxs.begin(),
						k->patternsIdxs.end());
				q.push(child.second);
			}
		}
	}
	vector<bool> match(const string &str) {
		vector<bool> rt(patterns.size());
		trie_node *k = root;
		for (int i = 0; i < str.size(); i++) {
			fail(k, str[i]);
			for (auto &it : k->patternsIdxs)
				rt[it] = true;
		}
		return rt;
	}
};

int main() {
	run();
	string s;
	int n;
	cin >> s >> n;
	vector<string> patterns(n);
	for (auto &it : patterns)
		cin >> it;
	aho_corasick aho(patterns);
	vector<bool> rt = aho.match(s);
	for (int i = 0; i < n; i++)
		cout << "NY"[rt[i]] << endl;
}
