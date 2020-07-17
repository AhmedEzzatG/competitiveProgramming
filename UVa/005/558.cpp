#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define endl '\n'
#define RT(v) return cout<<v,0
#define sz(v) (int)(v.size())
#define all(v) v.begin(),v.end()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}

struct edge {
	int from, to, weight;
	edge() { from = to = weight = 0; }
	edge(int from, int to, int weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return  weight < other.weight;
	}
};

vector<edge> edgeList;
bool bellmanford(int n) {
	vector<int> dis(n + 1, oo);
	dis[0] = 0;
	while (n--) {
		bool change = false;
		for (edge e : edgeList)
			if (dis[e.to] > dis[e.from] + e.weight) {
				dis[e.to] = dis[e.from] + e.weight;
				change = true;
			}
		if (!change) break;
		if (n == 0)return true;
	}
	return false;
}
int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		edgeList = vector<edge>();
		int n, m;
		cin >> n >> m;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			edgeList.push_back(edge(u, v, w));
		}
		cout << (bellmanford(n) ? "possible" : "not possible") << endl;
	}
}