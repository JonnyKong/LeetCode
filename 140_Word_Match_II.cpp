class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> current;
        vector<string> result;
        dfs(s, 0, wordDict, current, result);
        return result;
    }

    void dfs(string s, int cursor, const vector<string> &wordDict, vector<string> &current, vector<string> & result) {
        if (cursor == s.length()) {
            result.push_back(concat(current));
            return;
        }

        for (auto w : wordDict) {
            if (cursor + w.length() > s.length()) {
                continue;
            }

            if (w == s.substr(cursor, w.length())) {
                current.push_back(w);        
                dfs(s, cursor + w.length(), wordDict, current, result);
                current.pop_back();
            }
        }
    }

    string concat(const vector<string> & s) {
        if (s.size() == 0) {
            return "";
        }
        
        string ret = s[0];
        for (int i = 1; i < s.size(); i++) {
            ret += ' ';
            ret += s[i];
        }
        return ret;
    }
};
