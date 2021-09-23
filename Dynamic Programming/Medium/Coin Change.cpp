class Solution {
public:
    int dp[10005];
    int inf = 1e5 + 6;
    int solve(vector<int>&coins, int amount) {
        if (amount < 0) return inf;
        if (amount == 0) return 0;
        if (dp[amount] != -1) return dp[amount];
        int ans = inf;
        for (auto x : coins) {
            int res = 1 + solve(coins, amount - x);
            ans = min(ans, res);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount);
        return ans == inf ? -1 : ans;
    }
};