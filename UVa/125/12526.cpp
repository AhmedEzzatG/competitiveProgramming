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
			if (!t[root].have_next(ch))
				t[root][ch] = add_node();
			root = t[root][ch];
		}
		t[root].is_leaf = true;
	}
	int calc(const string &s) {
		int root = t[0][s[0]], press = 1;
		for (int i = 1; i < sz(s); i++) {
			if (t[root].is_leaf || sz(t[root].next) > 1)
				press++;
			root = t[root][s[i]];
		}
		return press;
	}
};

int main() {
	run();
	int n;
	while (cin >> n) {
		trie t;
		vector<string> v(n);
		for (auto &s : v) {
			cin >> s;
			t.insert(s);
		}
		int avr = 0;
		for (auto &s : v)
			avr += t.calc(s);
		cout << fixed << setprecision(2) << (avr + 0.001) / n << endl;
	}
}