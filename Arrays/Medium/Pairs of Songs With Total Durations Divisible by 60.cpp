class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        /*
            30 20 150 100 40
            30 20 30 40 40
        */
        int cnt = 0;
        unordered_map<int, int> mp;
        for (auto x : time) {
            int val = (60 - x % 60) == 60 ? 0 : (60 - x % 60);
            cnt += mp[val];
            mp[x % 60]++;
        }
        return cnt;

    }
};