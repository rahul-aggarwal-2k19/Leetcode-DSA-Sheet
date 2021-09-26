class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        vector<unordered_map<int, int>> mp(n);
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = nums[j] - nums[i];
                if (mp[i].find(d) != mp[i].end()) {
                    mp[j][d] = mp[i][d] + 1;
                }
                else {
                    mp[j][d] = 2;
                }
                ans = max(ans, mp[j][d]);
            }
        }
        return ans;
    }
};