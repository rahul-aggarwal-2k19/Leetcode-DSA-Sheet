class Solution {
public:
    int dp[200][200];
    int solve(int n, int m) {
        if (m == 1 && n == 1) return 1;
        if (m <= 0 or n <= 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = solve(n - 1, m) + solve(n, m - 1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(m, n);
        return ans;
    }
};