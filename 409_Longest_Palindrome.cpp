class Solution {
 public:
  int longestPalindrome(string s) {
    if (s.length() == 0) return 0;

    vector<int> cnt(52, 0);
    int result = 0;

    for (int i = 0; i < s.length(); ++i) {
      // for(int i = 0; i < 52; ++i) { cout << cnt[i] << ' '; } cout << endl;
      if (s[i] > 'Z') {
        ++cnt[s[i] - 'a' + 26];
      } else {
        ++cnt[s[i] - 'A'];
      }
    }

    for (int i = 0; i < 52; ++i) {
      int tmp = (((cnt[i]) >> 1) << 1);
      result += tmp;
      cnt[i] -= tmp;
    }

    for (int i = 0; i < 52; ++i) {
      if (cnt[i] == 1) {
        result += 1;
        break;
      }
    }

    return result;
  }
};
