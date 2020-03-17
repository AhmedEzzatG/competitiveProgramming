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

const int N = 509;
bool adj[N][N];
int main() {
	run();
	int n;
	int I = 0;
	while (cin >> n, n) {
		cout << "Case " << ++I << ", ";
		memset(adj, 0, sizeof(adj));
		map<string, int> mp;
		vector<string> v;
		while (n--) {
			int m;
			cin >> m;
			vector<string> tmp(m);
			for (auto &it : tmp) {
				cin >> it;
				if (mp.find(it) == mp.end()) {
					mp[it] = sz(mp);
					v.push_back(it);
				}
			}
			for (int i = 0; i + 1 < sz(tmp); i++)
				adj[mp[tmp[i]]][mp[tmp[i + 1]]] = 1;
		}
		cin >> n;
		while (n--) {
			string x, y;
			cin >> x >> y;
			adj[mp[x]][mp[y]] = 1;
		}
		n = sz(mp);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					adj[i][j] |= adj[i][k] && adj[k][j];
		vector<pair<string, string>> out;
		for (int i = 0; i < sz(v); i++)
			for (int j = i + 1; j < sz(v); j++)
				if (adj[i][j] == 0 && adj[j][i] == 0)
					out.push_back( { v[i], v[j] });
		if (out.empty()) {
			cout << "no concurrent events.\n";
		} else {
			cout << sz(out) << " concurrent events:\n";
			for (int i = 0; i < 2 && i < sz(out); i++)
				cout << "(" + out[i].first + "," + out[i].second + ") ";
			cout << endl;
		}
	}
}