class Solution {
public:
    int dp[1000][1000];
    int solve(string &s, int i, int j) {

        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1);
        }
        else {
            return dp[i][j] = min(solve(s, i + 1, j), solve(s, i, j - 1)) + 1;
        }
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.length() - 1);
    }
};