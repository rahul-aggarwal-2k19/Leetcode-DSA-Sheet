class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;

        int last = nums[0];
        int idx = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == last) continue;
            nums[idx] = nums[i];
            last = nums[i];
            idx++;
        }
        return idx;
    }
};