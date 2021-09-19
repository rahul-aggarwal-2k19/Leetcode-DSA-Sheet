class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int res = -1;
        for (auto x : nums) {
            if (cnt == 0) {
                res = x;
            }
            if (x == res) cnt++;
            else cnt--;
        }
        return res;
    }
};