#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}

int maxHistogramArea(vector<int> v) {
	stack<int> st;
	int maxArea = 0, area = 0;
	int i = 0;
	while (i < sz(v)) {
		if (st.empty() || v[st.top()] <= v[i])
			st.push(i++);
		else {
			int top = st.top(); st.pop();
			if (st.empty())
				area = v[top] * i;
			else
				area = v[top] * (i - st.top() - 1);
			maxArea = max(maxArea, area);
		}
	}
	while (!st.empty()) {
		int top = st.top(); st.pop();
		if (st.empty())
			area = v[top] * i;
		else
			area = v[top] * (i - st.top() - 1);
		maxArea = max(maxArea, area);
	}
	return maxArea;
}

int main() {
	run();
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		cin >> v[i][j];
	vector<int> height(m);
	int maxRectangular = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 0)height[j] = 0;
			else height[j]++;
		}
		maxRectangular = max(maxRectangular, maxHistogramArea(height));
	}
	cout << maxRectangular;
}
