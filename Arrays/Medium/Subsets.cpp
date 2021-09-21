class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int> &nums, int idx, vector<int>&v) {
        if (nums.size() == idx) {
            st.insert(v);
            return;
        }

        solve(nums, idx + 1, v);
        v.push_back(nums[idx]);
        solve(nums, idx + 1, v);
        v.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(nums, 0, v);
        vector<vector<int>> res;
        for (auto x : st) {
            res.push_back(x);
        }
        return res;
    }
};