#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
class BestView {
public:
	int dcmp(double x, double y) {
		if (fabs(x - y) < 1e-6)
			return 0;
		return (x < y ? -1 : 1);
	}
	int numberOfBuildings(vector<int> v) {
		int mx = 0;
		for (int i = 0; i < sz(v); i++) {
			int cnt = 0;
			for (int j = 0; j < sz(v); j++) {
				if (abs(j - i) <= 1) {
					cnt += abs(j - i);
					continue;
				}
				int mnIdx = min(i, j), mxIdx = max(i, j);
				double cur = v[mnIdx];
				double dif = (v[mxIdx] - v[mnIdx]) / (double) abs(i - j);
				bool valid = true;
				for (int k = mnIdx + 1; k < mxIdx; k++) {
					cur += dif;
					if (dcmp(cur, v[k]) <= 0)
						valid = false;
				}
				if (valid)
					cnt++;
			}
			mx = max(mx, cnt);
		}
		return mx;
	}
};