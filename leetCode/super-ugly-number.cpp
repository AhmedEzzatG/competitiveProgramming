class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		set<long long> st;
		st.insert(1);
		long long ugly = 0;
		while (n--) {
			ugly = *st.begin(); st.erase(st.begin());
			for (auto it : primes)
				st.insert(ugly * it);
		}
		return ugly;
	}
};
