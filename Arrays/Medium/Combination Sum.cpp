class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>&arr, int idx, int target, vector<int> &v) {
        if (target == 0) {
            st.insert(v);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            if (arr[i] <= target) {
                v.push_back(arr[i]);
                solve(arr, i, target - arr[i], v);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        st.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        solve(candidates, 0, target, v);
        vector<vector<int>> res;
        for (auto x : st) {
            res.push_back(x);
        }
        return res;
    }
};