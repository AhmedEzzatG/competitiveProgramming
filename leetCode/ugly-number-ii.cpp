class Solution {
public:
	int nthUglyNumber(int n) {
		vector<long long> primes = { 2,3,5 };
		set<long long> st;
		st.insert(1);
		long long last = 1;
		while (n--) {
			last = *st.begin(); st.erase(st.begin());
			for (auto it : primes)
				st.insert(last * it);
		}
		return last;
	}
};
