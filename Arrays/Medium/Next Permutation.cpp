class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int idx = n - 1;
        for (; idx >= i; idx--) {
            if (nums[idx] > nums[i]) break;
        }

        swap(nums[idx], nums[i]);
        reverse(nums.begin() + i + 1, nums.end());

    }
};