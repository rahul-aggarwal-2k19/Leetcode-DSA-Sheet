class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    st.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
                }
            }
        }
        return st.size();
    }
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> mp;
        for (auto x : nums) mp[x]++;
        int res = 0;
        for (auto x : mp) {
            if (k == 0 && mp[x.first] > 1) res++;
            else if (k > 0 && mp.find(x.first + k) != mp.end()) res++;
        }
        return res;
    }
};