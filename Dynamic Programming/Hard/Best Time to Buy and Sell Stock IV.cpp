class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int maxValue = INT_MIN;
            for (int j = 1; j < n; j++) {
                maxValue = max(maxValue, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], maxValue + prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};