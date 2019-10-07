class Solution {
public:
	string s1, s2;
	vector<vector<vector<int>>> mem;
	bool isScramble(int index1, int index2, int length) {
        int& rt = mem[index1][index2][length];
        if (~rt)return rt;
        rt = 1;
        for (int i = 0; i < length; i++)
            if (s1[index1 + i] != s2[index2 + i]) {
                rt = 0; break;
            }
        for (int mid = 1; mid < length; mid++) {
            rt = rt || (isScramble(index1, index2, mid)
                && isScramble(index1 + mid, index2 + mid, length - mid));
            rt = rt || (isScramble(index1 + mid, index2, length - mid) &&
                isScramble(index1, index2 + length - mid, mid));
        }
        return rt;
    }

	bool isScramble(string s1, string s2) {
		this->s1 = s1;
		this->s2 = s2;
		int sz = s1.size();
		mem = vector<vector<vector<int>>>(sz, vector<vector<int>>(sz, vector<int>(sz + 1, -1)));
		return isScramble(0, 0, sz);
	}
};
