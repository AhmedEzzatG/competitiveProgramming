#include<bits/stdc++.h>
using namespace std;

void coordinateCompress(vector<int>& axes, vector<int>& iToV,
	map<int, int>& vToI, int start = 2, int step = 2) {
	for (auto it : axes) vToI[it] = 0;
	iToV.resize(start + step * vToI.size());
	int idx = 0;
	for (auto& it : vToI) {
		it.second = start + step * idx;
		iToV[it.second] = it.first;
		idx++;
	}
}
