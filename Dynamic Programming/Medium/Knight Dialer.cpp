class Solution {
public:
    long long dp[5005][4][3];
    const int mod = 1e9 + 7;
    long long solve(int i, int j, int n) {
        if (i < 0 or j < 0 or i >= 4 or j >= 3 or (i == 3 && j != 1)) return 0;
        if (n == 1) return 1;
        if (dp[n][i][j] != -1) return dp[n][i][j] % mod;
        dp[n][i][j] =
            (solve(i - 1, j + 2, n - 1) % mod + solve(i - 1, j - 2, n - 1) % mod +
             solve(i + 1, j - 2, n - 1) % mod + solve(i + 1, j + 2, n - 1) % mod +
             solve(i - 2, j - 1, n - 1) % mod + solve(i - 2, j + 1, n - 1) % mod +
             solve(i + 2, j - 1, n - 1) % mod + solve(i + 2, j + 1, n - 1) % mod) % mod;
        return dp[n][i][j];
    }
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                int x = solve(i, j, n) % mod;
                ans += x;
                ans %= mod;
            }
        }
        return ans;
    }
};