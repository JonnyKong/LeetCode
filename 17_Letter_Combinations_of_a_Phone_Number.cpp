class Solution {
 private:
  vector<string> data{"",    "",    "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> dfs(const string& str) {
    vector<string> result;
    if (str.empty()) return result;
    if (str.length() == 1) {
      string temp = data[str[0] - '0'];
      for (int i = 0; i < temp.length(); ++i) {
        result.push_back(temp.substr(i, 1));
      }
    } else {
      vector<string> sub = dfs(str.substr(1, str.length() - 1));
      string first = data[str[0] - '0'];
      for (int i = 0; i < first.length(); ++i) {
        for (int j = 0; j < sub.size(); ++j) {
          result.push_back(first.substr(i, 1) + sub[j]);
        }
      }
    }
    return result;
  }

 public:
  vector<string> letterCombinations(string digits) { return dfs(digits); }
};