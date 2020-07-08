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
const double PI = acos(-1), EPS = 1e-3;
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
int dcmp(double x, double y) {
	if (fabs(x - y) <= EPS)return 0;
	return (x > y ? 1 : -1);
}

struct edge {
	int from, to;
	double temp, weight;
	edge(int from, int to, double weight, double temp) :
		from(from), to(to), weight(weight), temp(temp) {}
	bool operator <(const edge& other) const {
		return  dcmp(weight, other.weight) > 0;
	}
};

vector<vector<edge>> adj;
pair<double,vector<int>> dijkstra(int src, int dest, double t) {
	priority_queue<edge> q;
	vector<double> dis(adj.size(), (double)(oo)* oo);
	vector<int> prev(adj.size(), -1);
	q.push(edge(-1, src, 0, 0));
	dis[src] = 0;
	while (!q.empty()) {
		edge e = q.top(); q.pop();
		for (edge ne : adj[e.to])
			if (dcmp(ne.temp, t) <= 0 && dcmp(dis[ne.to], dis[e.to] + ne.weight) > 0) {
				ne.weight = dis[ne.to] = dis[e.to] + ne.weight;
				prev[ne.to] = e.to;
				q.push(ne);
			}
	}
	vector<int> path;
	int end = dest;
	while (end != -1) {
		path.push_back(end);
		end = prev[end];
	}
	reverse(all(path));
	if (dcmp(dis[dest], (double)(oo)* oo) >= 0)
		return { -1,path };
	else return { dis[dest],path };
}

int main() {
	run();
	int n, m;
	while (cin >> n >> m) {
		adj = vector<vector<edge>>(n + 1);
		int src, dest;
		cin >> src >> dest;
		while (m--) {
			int u, v;
			double c, t;
			cin >> u >> v >> t >> c;
			adj[u].push_back(edge(u, v, c, t));
			adj[v].push_back(edge(v, u, c, t));
		}
		double st = 0, ed = 50, md, ans = 40;
		while (dcmp(st, ed) <= 0) {
			md = (st + ed) / 2.0;
			double cost = dijkstra(src, dest, md).first;
			if (cost != -1) {
				ed = md - EPS;
				ans = md;
			}
			else st = md + EPS;
		}
		pair<double, vector<int>> p = dijkstra(src, dest, ans);
		cout << p.second[0];
		for (int i = 1; i < sz(p.second); i++)
			cout << ' ' << p.second[i];
		cout << endl;
		cout << fixed << setprecision(1) << p.first << ' ' << ans << endl;
	}
}