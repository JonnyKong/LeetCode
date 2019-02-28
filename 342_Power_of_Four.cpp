class Solution {
 public:
  bool isPowerOfFour(int num) {
    long long i = 1;
    while (i < ((long long)1 << 32)) {
      if (i == num)
        return 1;
      else if (i > num)
        return 0;
      i <<= 2;
    }
    return 0;
  }
};