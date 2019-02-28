class Solution {
 public:
  string convertToTitle(int n) {
    if (n < 27)
      return string(1, n + 64);
    else
      return convertToTitle((n - 1) / 26) + string(1, (n - 1) % 26 + 65);
  }
};