class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<vector<bool>>&vis, int &cnt) {
        if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0 or vis[i][j]) return;

        cnt += 1;
        vis[i][j] = true;
        dfs(grid, i + 1, j, n, m, vis, cnt);
        dfs(grid, i - 1, j, n, m, vis, cnt);
        dfs(grid, i, j + 1, n, m, vis, cnt);
        dfs(grid, i, j - 1, n, m, vis, cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int cnt = 0;
                    dfs(grid, i, j, n, m, visited, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};