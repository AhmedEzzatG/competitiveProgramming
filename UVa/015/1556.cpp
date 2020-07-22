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
		map<string, int> next;
		trie_node() {
		}
		bool have_next(string ch) {
			return next.find(ch) != next.end();
		}
		int& operator[](string ch) {
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
	void insert(const vector<string> &s) {
		int root = 0;
		for (const string &ch : s) {
			if (!t[root].have_next(ch))
				t[root][ch] = add_node();
			root = t[root][ch];
		}
	}
	void print(int root = 0, int dep = 0) {
		for (auto &it : t[root].next) {
			cout << string(dep, ' ') << it.first << endl;
			print(it.second, dep + 1);
		}
	}
};

int main() {
	run();
	int n;
	while (cin >> n) {
		cin.ignore();
		trie t;
		while (n--) {
			string s;
			vector<string> v;
			getline(cin, s);
			for (auto &it : s)
				if (it == '\\')
					it = ' ';
			stringstream ss(s);
			while (ss >> s)
				v.push_back(s);
			t.insert(v);
		}
		t.print();
		cout << endl;
	}
}