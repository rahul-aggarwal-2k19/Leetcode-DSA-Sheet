class Solution {
public:
    int n;
    int dp[1000][1000];
    int solve(vector<int> &arr, int i, int j) {
        if (i > j) return 0;
        if (i == j) {
            int x = arr[i];
            if (i + 1 < n) x *= arr[i + 1];
            if (i - 1 >= 0) x *= arr[i - 1];
            return x;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; k++) {
            int x = arr[k];
            if (j + 1 < n) {
                x *= arr[j + 1];
            }
            if (i - 1 >= 0) {
                x *= arr[i - 1];
            }

            x += solve(arr, i, k - 1) + solve(arr, k + 1, j);
            ans = max(x, ans);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for (auto x : nums) arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, n - 2);
    }
};