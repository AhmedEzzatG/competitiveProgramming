#include<bits/stdc++.h>
using namespace std;

void LIS_binarySearch(vector<int> v) {
	int n = v.size();
	vector<int> last(n), prev(n, -1);
	int length = 0;
	auto BS = [&](int val) {
		int st = 1, ed = length, md, rt = length;
		while (st <= ed) {
			md = st + ed >> 1;
			if (v[last[md]] >= val)
				ed = md - 1, rt = md;
			else st = md + 1;
		}
		return rt;
	};
	for (int i = 1; i < n; i++) {
		if (v[i] < v[last[0]]) last[0] = i;
		else if (v[i] > v[last[length]]) {
			prev[i] = last[length];
			last[++length] = i;
		}
		else {
			int index = BS(v[i]);
			prev[i] = last[index - 1];
			last[index] = i;
		}
	}
	cout << length + 1 << "\n-\n";
	vector<int> out;
	for (int i = last[length]; i >= 0; i = prev[i])
		out.push_back(v[i]);
	reverse(out.begin(),out.end());
	for (auto it : out)cout << it << endl;
}
