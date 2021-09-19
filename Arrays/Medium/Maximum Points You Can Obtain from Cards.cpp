class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int ans = sum;
        int left = k - 1;
        for (int i = n - 1; left >= 0; i--, left--) {
            sum -= cardPoints[left];
            sum += cardPoints[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};