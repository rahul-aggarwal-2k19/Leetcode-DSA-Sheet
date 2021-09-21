class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        int ans = INT_MIN;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int sum = points[i][0] + points[i][1];
            while (!pq.empty() && (points[i][0] - pq.top().second) > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans = max(ans, sum + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0], points[i][0]});
        }
        return ans;
    }
};