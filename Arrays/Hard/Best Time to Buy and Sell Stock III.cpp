class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int buy = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            left[i] = max(left[i - 1], prices[i] - buy);
        }

        int sell = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] > sell) {
                sell = prices[i];
            }
            right[i] = max(right[i + 1], sell - prices[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};