class Solution {
public:

    bool dfs(vector<vector<char>>&mat, int i, int j, int idx, vector<vector<bool>> &vis, string w) {
        if (idx == w.length()) return true;
        if (i < 0 or j < 0 or i >= mat.size() or j >= mat[0].size() or vis[i][j]) return false;

        if (mat[i][j] == w[idx]) {
            vis[i][j] = true;
            bool l = dfs(mat, i, j - 1, idx + 1, vis, w);
            bool r = dfs(mat, i, j + 1, idx + 1, vis, w);
            bool u = dfs(mat, i - 1, j, idx + 1, vis, w);
            bool d = dfs(mat, i + 1, j, idx + 1, vis, w);
            vis[i][j] = false;
            return l || r || u || d;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    bool isFound = dfs(board, i, j, 0, visited, word);
                    if (isFound) return true;
                }
            }
        }

        return false;

    }
};