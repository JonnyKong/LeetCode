class Solution {
 public:
  bool helper(const string& s, int i, int j) {
    // cout << "calling helper with " << i << ' ' << j << endl;
    for (int k = i; k <= (i + j) / 2; ++k) {
      if (s[k] != s[j - k + i]) return false;
    }
    // cout << "substring true" << endl;
    return true;
  }

  bool validPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (s[left] == s[right]) {
        ++left;
        --right;
      } else {
        return (helper(s, left, right - 1) || helper(s, left + 1, right));
      }
    }
    return true;
  }
};
