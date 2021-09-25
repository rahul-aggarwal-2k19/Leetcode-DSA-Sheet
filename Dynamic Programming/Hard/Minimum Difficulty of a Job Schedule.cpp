class Solution {
public:
    const int inf = 1e5 + 2;
    int dp[400][50];
    int solve(vector<int> &arr, int n, int d) {
        if (n < d) return inf;
        if (d < 0) return inf;
        if (d == 1) return *max_element(arr.begin(), arr.begin() + n);
        if (dp[n][d] != -1) return dp[n][d];
        int mx = -1;
        int ans = inf;
        for (int i = 1; i < n; i++) {
            mx = max(mx, arr[n - i]);
            ans = min(ans, solve(arr, n - i, d - 1) + mx);
        }
        return dp[n][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(jobDifficulty, jobDifficulty.size(), d);
        return ans == inf ? -1 : ans;
    }
};