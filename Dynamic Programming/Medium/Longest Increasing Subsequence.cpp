class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (it == v.end()) {
                v.push_back(nums[i]);
                ans = max(ans, (int)v.size());
            }
            else {
                int idx = it - v.begin();
                v[idx] = nums[i];
            }
        }
        return ans;
    }
};