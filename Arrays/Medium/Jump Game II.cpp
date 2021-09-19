class Solution {
public:
    int dp[100000];
    int solve(vector<int>&arr, int idx) {

        if (idx >= arr.size() - 1) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = 1e7 + 10;
        for (int step = 1; step <= arr[idx]; step++) {
            int x = 1 + solve(arr, idx + step);
            ans = min(ans, x);
        }
        return dp[idx] = ans;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0);
        return ans;
    }
};