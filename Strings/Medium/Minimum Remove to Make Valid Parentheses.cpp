class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int n = s.length();
        unordered_set<int> valid;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push({s[i], i});
            }
            else if (s[i] == ')') {
                if (st.empty()) continue;
                valid.insert(st.top().second);
                st.pop();
                valid.insert(i);
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (valid.find(i) != valid.end()) {
                    ans += s[i];
                }
            }
            else if (s[i] == ')') {
                if (valid.find(i) != valid.end()) {
                    ans += s[i];
                }
            }
            else if (isalpha(s[i])) {
                ans += s[i];
            }
        }
        return ans;
    }
};