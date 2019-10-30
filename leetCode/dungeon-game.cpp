class Solution {
public:
	vector<vector<int>> v, mem, vis;
	int n, m;
	int solve(int r, int c) {
		if (r >= n || c >= m) return -1e9;
		if (r == n - 1 && c == m - 1) return min(0, v[r][c]);
		int& rt = mem[r][c];
		if (vis[r][c])return rt;
		vis[r][c] = 1;
		rt = max(solve(r + 1, c), solve(r, c + 1)) + v[r][c];
		return rt = min(0, rt);
	}
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		v = dungeon;
		n = v.size(); m = v[0].size();
		vis = mem = vector<vector<int>>(n + 1, vector<int>(m + 1));
		return max(1, 1- solve(0, 0));
	}
};
