class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
        unordered_map<int, int> mp = {{0, -1}};
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            cur = (cur + A[i]) % (k);
            mp.insert({cur, i});
            if (i - mp[cur] > 1) return true;
        }
        return false;
    }
};