class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur = 0;
        for (auto x : nums) {
            cur += x;
            res = max(res, cur);
            if (cur < 0) cur = 0;
        }
        return res;
    }
};