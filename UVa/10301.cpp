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
	int from, to;
	double weight;
	edge() {}
	edge(int from, int to, double weight) :from(from), to(to), weight(weight) {}
	bool operator <(const edge& other) const {
		return weight < other.weight;
	}
};
vector<edge> edgeList;

struct DSU {
	vector<int> rank, parent, size;
	int	forsets;
	DSU(int n) {
		size = rank = parent = vector<int>(n + 1);
		forsets = n;
		for (int i = 0; i <= n; i++)
			size[i] = rank[i] = 1, parent[i] = i;
	}
	int find_set(int x) {
		if (x == parent[x])return x;
		return parent[x] = find_set(parent[x]);
	}
	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			if (rank[x] > rank[y])swap(x, y);
			parent[x] = y;
			size[y] += size[x];
			if (rank[x] == rank[y])rank[y]++;
			forsets--;
		}
		return x != y;
	}
	bool same_set(int x, int y) {
		return find_set(x) != find_set(y);
	}
	int size_set(int x) {
		return size[find_set(x)];
	}
};

typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b) (b - a)
#define length(a) (hypot(a.Y,a.X))
#define angle(a) (atan2(a.Y,a.X))
#define normalize(a) (a/(length(a)))
#define dp(a,b) ((conj(a)*b).X)	// a*b cos(T), if zero -> prep
#define cp(a,b) ((conj(a)*b).Y) // a*b sin(T), if zero -> parllel
#define lengthSqr(a) (dp(a,a))
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }

bool same(point p1, point p2) {
	return dp(vec(p1, p2), vec(p1, p2)) < EPS;
}

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

double getAngle_A_abc(double a, double b, double c) {
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}

bool intersectCircleCircle(point c1, double r1, point c2, double r2) {
	// Handle infinity case first: same center/radius and r > 0
	if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
		return 1;  // infinity 2 same circles (not points)

	  // Compute 2 intersection case and handle 0, 1, 2 cases
	double ang1 = angle(vec(c1, c2)), ang2 = getAngle_A_abc(r2, r1, length(vec(c1, c2)));

	if (::isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
		ang2 = 0; // fix corruption

	vector<point> v(1, polar(r1, ang1 + ang2) + c1);

	// if point NOT on the 2 circles = no intersection
	if (dcmp(dp(vec(c1, v[0]), vec(c1, v[0])), r1 * r1) != 0 ||
		dcmp(dp(vec(c2, v[0]), vec(c2, v[0])), r2 * r2) != 0)
		return 0;

	v.push_back(polar(r1, ang1 - ang2) + c1);
	if (same(v[0], v[1]))  // if same, then 1 intersection only
		v.pop_back();
	return (sz(v) == 2);
}


int main() {
	run();
	int n;
	while (cin >> n, ~n) {
		vector<pair<point, double>> v(n);
		DSU uf(n);
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y >> v[i].second;
			v[i].first = point(x, y);
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (intersectCircleCircle(v[i].first, v[i].second, v[j].first, v[j].second))
					uf.union_sets(i, j);
			}
		int mx = 0;
		for (int i = 0; i < n; i++)
			mx = max(mx, uf.size_set(i));
		cout << "The largest component contains " << mx << " ring";
			if (mx == 1)cout << ".\n";
			else  cout << "s.\n";

	}
}
