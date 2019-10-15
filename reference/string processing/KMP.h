#include<bits/stdc++.h>
using namespace std;

vector<int> failure_function(string pattern) {
	int m = pattern.size();
	vector<int> longestPrefix(m);
	for (int i = 1, k = 0; i < m; i++) {
		while (k > 0 && pattern[k] != pattern[i])
			k = longestPrefix[k - 1];
		if (pattern[k] == pattern[i])k++;
		longestPrefix[i] = k;
	}
	return longestPrefix;
}

void KMP(string str, string pattern) {
	int n = str.size();
	int m = pattern.size();
	vector<int> longestPrefix = failure_function(pattern);
	for (int i = 0, k = 0; i < n; i++) {
		while (k > 0 && pattern[k] != str[i])
			k = longestPrefix[k - 1];
		if (pattern[k] == str[i])k++;
		if (k == m) {
			cout << i - m + 1 << endl;
			k = longestPrefix[k - 1]; // if you want next match
		}
	}
}
