class Solution {
public:
	vector<vector<int>> v, mem;
	vector<int> dr, dc;
	bool valid(int i, int j) {
		return  0 <= i && i < v.size() && 0 <= j && j < v[i].size();
	}
	int solve(int i, int j) {
		int& rt = mem[i][j];
		if (~rt)return rt;
		rt = 1;
		for (int k = 0; k < 4; k++) {
			int x = i + dr[k], y = j + dc[k];
			if (valid(x, y) && v[i][j] < v[x][y])
				rt = max(rt, 1 + solve(x, y));
		}
		return rt;
	}
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty())return 0;
		dr = { 1,-1,0,0 };
		dc = { 0,0,1,-1 };
		int rt = 0;
		v = matrix;
		int n = v.size(), m = v[0].size();
		mem = vector<vector<int>>(n, vector<int>(m, -1));
	    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
			rt = max(rt, solve(i, j));
		return rt;
	}
};
