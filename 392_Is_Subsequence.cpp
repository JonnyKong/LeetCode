/**
 * Trivial greedy.
 *
 * Subsequence is different from substring.
 */

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    /* Sanity check */
    if (s.empty()) return true;
    if (s.length() > t.length()) return false;

    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
      if (s[i] == t[j++]) {
        if (++i == s.length()) return true;
      }
    }
    return false;
  }
};