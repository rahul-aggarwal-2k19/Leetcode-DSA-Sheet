class Solution {
public:
    int dp[10000];
    int helper(vector<int>&nums, int idx) {
        if (idx == nums.size()) return 0;
        if (dp[idx] == 0) {
            int earn = 0;
            int jump = idx;
            while (jump < nums.size() && nums[jump] == nums[idx]) {
                earn += nums[idx];
                jump++;
            }
            int skip = helper(nums, jump);
            while (jump < nums.size() && nums[jump] == (nums[idx] + 1)) jump++;
            int inc = earn + helper(nums, jump);
            dp[idx] = max(skip, inc);
        }
        return dp[idx];
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        memset(dp, 0, sizeof(dp));
        return helper(nums, 0);
    }
};