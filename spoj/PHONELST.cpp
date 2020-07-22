#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
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

class trie {
	struct trie_node {
		int cnt = 0;
		map<char, int> next;
		trie_node() {
		}
		bool have_next(char ch) {
			return next.find(ch) != next.end();
		}
		int& operator[](char ch) {
			return next[ch];
		}
	};
	vector<trie_node> t;
	int add_node() {
		t.push_back(trie_node());
		return t.size() - 1;
	}
public:
	trie() {
		add_node();
	}
	void insert(const string &s) {
		int root = 0;
		for (const char &ch : s) {
			t[root].cnt++;
			if (!t[root].have_next(ch))
				t[root][ch] = add_node();
			root = t[root][ch];
		}
		t[root].cnt++;
	}
	int get(const string &s) {
		int root = 0;
		for (const char &ch : s)
			root = t[root][ch];
		return t[root].cnt;
	}
};

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		trie t;
		vector<string> v(n);
		for (auto &s : v) {
			cin >> s;
			t.insert(s);
		}
		bool valid = true;
		for (auto &s : v) {
			if (t.get(s) != 1)
				valid = false;
		}
		cout << (valid ? "YES" : "NO") << endl;
	}
}
