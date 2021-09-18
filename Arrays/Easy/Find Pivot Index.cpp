class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int sum = 0;
        for (auto x : nums) sum += x;

        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            int right = sum - nums[i];
            if (left == right) return i;
            left += nums[i];
            sum -= nums[i];
        }
        return -1;
    }
};