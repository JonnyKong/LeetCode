class Solution {
 public:
  bool isMatch(string s, string p) {
    regex a(p);
    return regex_match(s, a);
  }
};