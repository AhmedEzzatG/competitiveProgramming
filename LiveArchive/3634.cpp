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

struct SetStackElement {
	set<SetStackElement> st;
	SetStackElement() {
		st.clear();
	}
	bool operator<(const SetStackElement &other) const {
		if (st.empty())
			return !other.st.empty();
		if (other.st.empty())
			return false;
		if (sz(st) != sz(other.st))
			return sz(st) < sz(other.st);
		auto it2 = other.st.begin();
		for (auto &it : st) {
			if (it < *it2 || *it2 < it)
				return it < *it2;
			it2++;
		}
		return false;
	}
};
int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		stack<int> stk;
		map<int, set<int>> st;
		map<set<int>, int> id;
		id[ { }] = 1;
		int cnt = 2;
		auto add = [&](const set<int> &s) {
			if (id[s] == 0) {
				id[s] = cnt;
				st[cnt] = s;
				cnt++;
			}
			return id[s];
		};
		while (n--) {
			string s;
			cin >> s;
			if (s == "PUSH")
				stk.push(1);
			else if (s == "DUP")
				stk.push(stk.top());
			else if (s == "ADD") {
				int a = stk.top();
				stk.pop();
				set<int> tmp = st[stk.top()];
				tmp.insert(a);
				stk.top() = add(tmp);
			} else if (s == "UNION") {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				if (sz(st[a]) < sz(st[b]))
					swap(a, b);
				set<int> tmp = st[a];
				for (auto &it : st[b])
					tmp.insert(it);
				stk.push(add(tmp));
			} else if (s == "INTERSECT") {
				int a = stk.top(), b;
				stk.pop();
				b = stk.top();
				stk.pop();
				set<int> tmp;
				if (sz(st[a]) > sz(st[b]))
					swap(a, b);
				for (auto &it : st[a])
					if (st[b].find(it) != st[b].end())
						tmp.insert(it);
				stk.push(add(tmp));
			}
			cout << sz(st[stk.top()]) << endl;
		}
		cout << "***\n";
	}
}