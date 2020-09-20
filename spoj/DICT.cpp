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
		bool is_leaf = false;
		map<char, int> next;
		bool have_next(char ch) {
			return next.find(ch) != next.end();
		}
		int& operator[](char ch) {
			return next[ch];
		}
	};
	vector<trie_node> t;
public:
	trie() {
		t.push_back(trie_node());
	}
	void insert(const string &s) {
		int root = 0;
		for (const char &ch : s) {
			if (!t[root].have_next(ch)) {
				t.push_back(trie_node());
				t[root][ch] = t.size() - 1;
			}
			root = t[root][ch];
		}
		t[root].is_leaf = true;
	}
	int get(const string &s) {
		int root = 0;
		for (const char &ch : s) {
			if (!t[root].have_next(ch))
				return -1;
			root = t[root][ch];
		}
		return root;
	}
	void print(int root, bool start, string &prefix) {
		if (t[root].is_leaf && !start) {
			cout << prefix << endl;
		}
		for (auto &it : t[root].next) {
			prefix += it.first;
			print(it.second, false, prefix);
			prefix.pop_back();
		}
	}
} t;

int main() {
	run();
	int n;
	cin >> n;
	vector<int> v;
	while (n--) {
		string s;
		cin >> s;
		t.insert(s);
	}
	cin >> n;
	for (int I = 1; I <= n; I++) {
		cout << "Case #" << I << ":\n";
		string s;
		cin >> s;
		int idx = t.get(s);
		if (idx == -1)
			cout << "No match.\n";
		else
			t.print(idx, true, s);
	}
}
