class Solution {
public:
    unordered_set<string> st;
    map<string, bool> mp;
    bool isPresent(string s) {
        return st.find(s) != st.end();
    }

    bool helper(string s) {
        if (s.length() == 0) return true;
        if (mp.find(s) != mp.end()) return false;
        for (int i = 1; i <= s.length(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (isPresent(left) && helper(right)) return mp[s] = true;
        }
        return mp[s] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        st.clear();
        mp.clear();
        for (auto x : wordDict) {
            st.insert(x);
        }

        return helper(s);
    }
};