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

struct cost {
	ll t, dis;
	cost() {
		t = dis = INF;
	}
	cost(ll t, ll dis) :
			t(t), dis(dis) {
	}
	cost operator +(const cost &other) const {
		return cost(t + other.t, dis + other.dis);
	}
	bool operator <(const cost &other) const {
		if (t != other.t)
			return t < other.t;
		return dis < other.dis;
	}
};

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<cost>> adj(n + 1, vector<cost>(n + 1));
		while (m--) {
			int a, b;
			ll t, d;
			cin >> a >> b >> t >> d;
			adj[a][b] = adj[b][a] = min(adj[a][b], cost(t, d));
		}
		for (int i = 1; i < sz(adj); i++)
			adj[i][i] = cost(0, 0);
		for (int k = 1; k < sz(adj); k++)
			for (int i = 1; i < sz(adj); i++)
				for (int j = 1; j < sz(adj); j++) {
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
		int q;
		cin >> q;
		while (q--) {
			int a, b;
			cin >> a >> b;
			if (adj[a][b].t < INF)
				cout << "Distance and time to reach destination is "
						<< adj[a][b].dis << " & " << adj[a][b].t << ".\n";
			else
				cout << "No Path.\n";
		}
		if (t)
			cout << endl;
	}
}