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
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
vector<vector<int>> adj;
vector<int> in, cur, vis;
vector<string> v;
map<string, int> mp;
vector<string> input() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	vector<string> rt;
	while (ss >> s)
		rt.push_back(s);
	sort(all(rt));
	return rt;
}

vector<int> split(string s, char ch) {
	int j = s.find(ch);
	return {mp[s.substr(0,j)],mp[s.substr(j+1)]};
}

bool solve() {
	if (sz(cur) == sz(v)) {
		for (int i = 0; i < sz(v); i++)
			cout << v[cur[i]] << " \n"[i + 1 == sz(v)];
		return true;
	}
	int rt = 0;
	for (int node = 0; node < sz(v); node++)
		if (!vis[node] && in[node] == 0) {
			vis[node] = true;
			for (int ch : adj[node])
				in[ch]--;
			cur.push_back(node);
			rt |= solve();
			for (int ch : adj[node])
				in[ch]++;
			cur.pop_back();
			vis[node] = false;
		}
	return rt;
}
int main() {
	run();
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		cin.ignore();
		v = input();
		mp.clear();
		for (int i = 0; i < sz(v); i++)
			mp[v[i]] = i;
		vector<string> edges = input();
		adj = vector<vector<int>>(sz(v));
		vis = in = vector<int>(sz(v));
		for (auto &s : edges) {
			auto tmp = split(s, '<');
			adj[tmp[0]].push_back(tmp[1]);
			in[tmp[1]]++;
		}
		if (!solve())
			cout << "NO\n";
		if (t)
			cout << endl;
	}
}
