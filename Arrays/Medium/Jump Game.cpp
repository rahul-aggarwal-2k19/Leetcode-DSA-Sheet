class Solution {
public:

    int dp[100000];
    bool helper(vector<int> &nums, int idx) {
        if (idx >= nums.size() - 1) return true;
        if (dp[idx] != -1) return dp[idx];
        for (int step = 1; step <= nums[idx]; step++) {
            if (helper(nums, idx + step)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0);
    }
};