class Solution {
public:

    int dp[102][10002];

    int helper(int k, int n) {

        if (n <= 1) return n;
        if (k == 1) return n;
        if (dp[k][n] != -1) return dp[k][n];
        int ans = 1e6 + 2;
        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int left = helper(k - 1, mid - 1);
            int right = helper(k, n - mid);
            ans = min(ans, 1 + max(left, right));
            if (left < right) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return helper(k, n);
    }
};