class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = board[i][j];
            }
        }

        int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = { -1, 0, 1, 1, -1, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live = 0;
                int dead = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 or x >= n or y < 0 or y >= m) continue;
                    live += board[x][y] == 1;
                    dead += board[x][y] == 0;
                }
                if (board[i][j] == 0) {
                    if (live == 3) {
                        res[i][j] = 1;
                    }
                }
                else {
                    if (live < 2 or live > 3) {
                        res[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = res[i][j];
            }
        }
    }
};