class Solution {
public:
    int countSubstrings(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][i] = true;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                dp[i][i + 1] = true;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 1, j = k; i <= n && j <= n; i++, j++) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cnt += dp[i][j];
            }
        }

        return cnt;

    }
};