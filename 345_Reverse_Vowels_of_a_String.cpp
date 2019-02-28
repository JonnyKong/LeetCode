class Solution {
 public:
  string reverseVowels(string s) {
    if (s.length() <= 1) return s;
    int i = -1, j = s.length();
    bool end_out = 0;
    while (1) {
      ++i;
      --j;
      while (s[i] != 'a' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' &&
             s[i] != 'u' && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' &&
             s[i] != 'O' && s[i] != 'U' && i < j) {
        ++i;
      }
      while (s[j] != 'a' && s[j] != 'e' && s[j] != 'o' && s[j] != 'i' &&
             s[j] != 'u' && s[j] != 'A' && s[j] != 'E' && s[j] != 'I' &&
             s[j] != 'O' && s[j] != 'U' && i < j) {
        --j;
      }
      if (i >= j) break;
      if (s[i] != s[j]) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
      }
    }
    return s;
  }
};