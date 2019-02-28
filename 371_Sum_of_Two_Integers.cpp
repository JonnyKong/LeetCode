class Solution {
 public:
  int getSum(int a, int b) {
    int c = 0;
    int p = 1;
    for (int i = 0; i < 32; ++i) {
      bool flag = (a & p && b & p) || (a & p && c & p) || (b & p && c & p);
      c ^= (a & p);
      c ^= (b & p);
      if (flag) c |= (p << 1);
      p <<= 1;
    }
    return c;
  }
};