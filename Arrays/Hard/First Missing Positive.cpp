class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (val > 0 && val < n && (val - 1) != i && nums[val - 1] != val) {
                swap(nums[val - 1], nums[i]);
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return (i + 1);
        }
        return n + 1;
    }
};