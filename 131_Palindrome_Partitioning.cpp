class Solution {
public:
    bool isP(const string & s, int l, int r) {
        for(int k = 0; k <= (r - l) / 2; ++k) {
            if(s[l + k] != s[r - k]) return false;
        }
        return true;
    }

    void dfs(const string & s, vector<string> & path, int pos,
                vector<vector<string>> & result) {

        if(pos == s.length()) {
            result.push_back(path);
            // cout << "push" << endl;
            return;
        }

        for(int i = pos + 1; i <= s.length(); ++i) {
            if(isP(s, pos, i - 1)) {
                path.push_back(s.substr(pos, i - pos));
                dfs(s, path, i, result);
                path.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        dfs(s, path, 0, result);
        return result;
    }
};
