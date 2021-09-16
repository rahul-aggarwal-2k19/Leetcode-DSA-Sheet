class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> current = intervals[i];
            if (current[0] <= end) {
                end = max(current[1], end);
            }
            else {
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                res.push_back(v);
                start = current[0];
                end = current[1];
            }
        }
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        res.push_back(v);
        return res;
    }
};