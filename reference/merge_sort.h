#include<bits/stdc++.h>
using namespace std;

long long cnt = 0;
vector<int> v, temp;

void merge_sort(int s, int e) {
	if (s + 1 >= e) return;
	int m = s + (e - s >> 1);
	merge_sort(s, m);
	merge_sort(m, e);
	for (int i = s; i < e; i++) temp[i] = v[i];
	int i = s, j = m, k = s;
	while (i < m && j < e)
		if (temp[i] <= temp[j]) v[k++] = temp[i++];
		else  v[k++] = temp[j++], cnt += j - k;
	while (i < m)v[k++] = temp[i++];
	while (j < e)v[k++] = temp[j++];
}
