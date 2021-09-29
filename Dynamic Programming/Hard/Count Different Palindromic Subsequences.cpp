class Solution {
public:
    long long int mod = 1000000007;
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        long long dp[n][n];
        long long next[n];
        long long prev[n];

        // prev
        unordered_map<char, long long> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                prev[i] = mp[s[i]];
            }
            else {
                prev[i] = -1;
            }
            mp[s[i]] = i;
        }
        unordered_map<char, long long> hash;
        for (int i = n - 1; i >= 0; i--) {
            if (hash.find(s[i]) != hash.end()) {
                next[i] = hash[s[i]];
            }
            else {
                next[i] = -1;
            }
            hash[s[i]] = i;
        }

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = 2;
        }
        for (int k = 2; k < n; k++) {
            for (int i = 0, j = k; j < n; i++, j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = dp[i + 1][j] % mod + dp[i][j - 1] % mod - dp[i + 1][j - 1] % mod;
                    dp[i][j] %= mod;
                }
                else {
                    int ni = next[i];
                    int pi = prev[j];
                    if (ni > pi) {
                        dp[i][j] = 2 * (dp[i + 1][j - 1] % mod) + 2;
                    }
                    else if (ni == pi) {
                        dp[i][j] = 2 * (dp[i + 1][j - 1] % mod) + 1;
                    }
                    else {
                        dp[i][j] = 2 * (dp[i + 1][j - 1] % mod) - (dp[ni + 1][pi - 1] % mod);
                    }
                    dp[i][j] %= mod;
                }
                dp[i][j] = dp[i][j] < 0 ? (dp[i][j] + mod) % mod : dp[i][j] % mod;
            }
        }
        return dp[0][n - 1];

    }
};