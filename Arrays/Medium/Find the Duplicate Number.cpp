class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int hare = nums[0];
        int tort = nums[0];
        do {
            hare = nums[nums[hare]];
            tort = nums[tort];
        } while (hare != tort);

        hare = nums[0];
        while (hare != tort) {
            hare = nums[hare];
            tort = nums[tort];
        }
        return hare;
    }
};