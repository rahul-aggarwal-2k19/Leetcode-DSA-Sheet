class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while (s < e) {
                int sum = nums[s] + nums[e];
                if (sum == target) {
                    st.insert({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                }
                else if (sum > target) {
                    e--;
                }
                else {
                    s++;
                }
            }
        }

        vector<vector<int>> res;
        for (auto x : st) {
            res.push_back(x);
        }
        return res;
    }
};