class Solution {
public:
    unordered_map<char, int> req;
    unordered_map<char, int> cur;

    bool isFound() {
        for (auto x : req) {
            if (cur.find(x.first) == cur.end() || cur[x.first] < x.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        req.clear();
        for (auto x : t) {
            req[x]++;
        }
        int start = 0;
        int end = 0;
        int ss = -1;
        int n = s.length();
        int maxlen = INT_MAX;
        while (end < n) {
            cur[s[end]]++;
            if (isFound()) {
                while (start < end && cur[s[start]] > req[s[start]]) {
                    cur[s[start]]--;
                    start++;
                }
                if (maxlen > (end - start + 1)) {
                    maxlen = end - start + 1;
                    ss = start;
                }
                cur[s[start]]--;
                start++;
            }
            end++;
        }
        if (ss == -1) return "";
        return s.substr(ss, maxlen);
    }
};