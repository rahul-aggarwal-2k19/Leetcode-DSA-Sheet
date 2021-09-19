class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> neg;
        vector<int> pos;
        for (auto x : nums) {
            if (x <= 0) {
                neg.push_back(x * x);
            }
            else {
                pos.push_back(x * x);
            }
        }
        reverse(neg.begin(), neg.end());
        int i = 0;
        int j = 0;
        vector<int> res;
        int n = pos.size();
        int m = neg.size();
        while (i < n && j < m) {
            if (pos[i] < neg[j]) {
                res.push_back(pos[i++]);
            }
            else {
                res.push_back(neg[j++]);
            }
        }
        while (i < n) {
            res.push_back(pos[i++]);
        }
        while (j < m) {
            res.push_back(neg[j++]);
        }
        return res;
    }
};