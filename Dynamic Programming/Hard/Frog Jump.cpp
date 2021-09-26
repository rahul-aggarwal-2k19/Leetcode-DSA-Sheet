class Solution {
public:

    unordered_map<int, bool> dp;

    bool canCross(vector<int>& stones) {

        unordered_map<int, unordered_set<int>> mp;
        mp[0].insert(0);
        for (auto pos : stones) {

            for (auto x : mp[pos]) {
                if ((x - 1) > 0) {
                    mp[pos + x - 1].insert(x - 1);
                }
                if (x > 0) {
                    mp[pos + x].insert(x);
                }
                if (x + 1 > 0) {
                    mp[pos + x + 1].insert(x + 1);
                }
            }
        }
        return mp[stones.back()].size() > 0;
    }
};