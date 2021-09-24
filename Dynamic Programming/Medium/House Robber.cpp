class Solution {
public:
    int rob(vector<int>& nums) {

        int inc = 0;
        int exc = 0;
        for (int i = 0; i < nums.size(); i++) {
            int newInc = exc + nums[i];
            int newExc = max(inc, exc);
            inc = newInc;
            exc = newExc;
        }
        return max(inc, exc);
    }
};