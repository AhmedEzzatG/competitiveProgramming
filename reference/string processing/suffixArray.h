#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()

int n;
vector<int> suf, order, tmp;
int getOrder(int a) {
	return (a < order.size() ? order[a] : 0);
}

void radix_sort(int k) {
	vector<int> frq(n);
	for (auto& it : suf) frq[getOrder(it + k)]++;
	for (int i = 1; i < n; i++)
		frq[i] += frq[i - 1];
	for (int i = n - 1; i >= 0; i--)
		tmp[--frq[getOrder(suf[i] + k)]] = suf[i];
	suf = tmp;
}

struct comp {
	int len;
	comp(int len) :len(len) {}
	bool operator ()(const int& a, const int& b) const {
		if (order[a] != order[b])
			return order[a] < order[b];
		return getOrder(a + len) < getOrder(b + len);
	}
};

// n*log(n)
void suffixArray(string s) {
	n = s.size() + 1;
	vector<int> newOrder(n);
	for (int i = 0; i < n; i++) {
		suf.push_back(i);
		tmp.push_back(s[i]);
	}
	sort(all(tmp));
	for (int i = 0; i < n; i++)
		order.push_back(lower_bound(all(tmp), s[i]) - tmp.begin());
	for (int len = 1; newOrder.back() != n - 1; len <<= 1) {
		//sort(all(suf), comp(len));
		radix_sort(len);
		radix_sort(0);
		for (int i = 1; i < n; i++)
			newOrder[i] = newOrder[i - 1] + comp(len)(suf[i - 1], suf[i]);
		for (int i = 0; i < n; i++)
			order[suf[i]] = newOrder[i];
	}
}


// return longest Common prefix in suffix array between (i,i-1)
// O(n)
vector<int> LCP(string s) {
	suffixArray(s);
	vector<int> rank(n), lcp(n);
	for (int i = 0; i < n; i++)
		rank[suf[i]] = i;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (rank[i]) {
			int j = suf[rank[i] - 1];
			while (s[i + c] == s[j + c])c++;
		}
		lcp[rank[i]] = c;
		if (c)c--;
	}
	return lcp;
}