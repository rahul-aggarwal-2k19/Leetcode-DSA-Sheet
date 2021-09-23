class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefix[i] = (prefix[i - 1] == 0 ? 1 : prefix[i - 1]) * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] == 0 ? 1 : suffix[i + 1]) * nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, max(prefix[i], suffix[i]));
        }
        return ans;
    }
};