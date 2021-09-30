class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int len = 0;
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int n = s.length();
        while (j < n) {
            if (mp[s[j]] == 0) {
                mp[s[j]]++;
                len++;
            }
            else {
                ans = max(ans, len);
                while (i < j && mp[s[j]] == 1) {
                    mp[s[i]]--;
                    i++;
                    len--;
                }
                mp[s[j]]++;
                len++;
            }
            j++;
        }
        ans = max(ans, len);
        return ans;
    }
};