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

int maxHistogramArea(vector<int> v) {
	stack<int> st;
	int maxArea = 0, area = 0;
	int i = 0;
	while (i < sz(v)) {
		if (st.empty() || v[st.top()] <= v[i])
			st.push(i++);
		else {
			int top = st.top();
			st.pop();
			if (st.empty())
				area = v[top] * i;
			else
				area = v[top] * (i - st.top() - 1);
			maxArea = max(maxArea, area);
		}
	}
	while (!st.empty()) {
		int top = st.top();
		st.pop();
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
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n + 2, vector<int>(n + 2));
		while (m--) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			v[x1][y1]++;
			v[x2 + 1][y1]--;
			v[x1][y2 + 1]--;
			v[x2 + 1][y2 + 1]++;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
		vector<int> dp(n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][j] == 0)
					dp[j]++;
				else
					dp[j] = 0;
			}
			ans = max(ans, maxHistogramArea(dp));
		}
		cout << ans << endl;
	}
}