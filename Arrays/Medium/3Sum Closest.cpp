class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = target - nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int x = nums[l] + nums[r];
                if (x == sum) return (x + nums[i]);
                else if (x > sum) {
                    if ((x - sum) < diff) {
                        diff = x - sum;
                        ans = x + nums[i];
                    }
                    r--;
                }
                else {
                    if ((sum - x) < diff) {
                        diff = sum - x;
                        ans = x + nums[i];
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};