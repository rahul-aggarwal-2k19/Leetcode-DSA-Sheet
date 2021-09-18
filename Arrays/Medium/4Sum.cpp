class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i];
            for (int j = i + 1; j < n; j++) {
                int b = nums[j];
                int x = target - a - b;
                int s = j + 1;
                int e = n - 1;
                while (s < e) {
                    int sum = nums[s] + nums[e];
                    if (sum == x) {
                        st.insert({a, b, nums[s], nums[e]});
                        s++;
                        e--;
                    }
                    else if (sum > x) {
                        e--;
                    }
                    else {
                        s++;
                    }
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