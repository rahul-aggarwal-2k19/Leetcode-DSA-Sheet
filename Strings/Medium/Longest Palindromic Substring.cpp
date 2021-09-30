class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        int start = -1;
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; j++, i++) {
                if (g == 0) {
                    dp[i][j] = true;
                    int len = j - i + 1;
                    if (len > ans) {
                        ans = len;
                        start = i;
                    }
                }
                else if (g == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                        int len = j - i + 1;
                        if (len > ans) {
                            ans = len;
                            start = i;
                        }
                    }
                }
                else {
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        int len = j - i + 1;
                        if (len > ans) {
                            ans = len;
                            start = i;
                        }
                    }
                }
            }
        }
        if (start == -1) return "";
        return s.substr(start, ans);
    }
};