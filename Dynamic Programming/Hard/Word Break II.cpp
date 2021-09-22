class Solution {
public:
    vector<string> res;
    unordered_set<string> st;
    bool isPresent(string s) {
        return st.find(s) != st.end();
    }

    void helper(string s, string ssf) {
        if (s.length() == 0) {
            ssf.pop_back();
            res.push_back(ssf);
            return;
        }
        for (int i = 1; i <= s.length(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (isPresent(left)) {
                helper(right, ssf + left + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.clear();
        for (auto x : wordDict) {
            st.insert(x);
        }
        res.clear();
        helper(s, "");
        return res;
    }
};