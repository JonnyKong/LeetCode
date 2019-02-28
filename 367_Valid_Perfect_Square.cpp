class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 0) return 1;
    long long hi = 1, lo = 1;
    while (hi * hi < num) hi <<= 1;
    lo = hi >> 1;
    while (lo < hi) {
      auto mid = (hi + lo) / 2;
      if (mid * mid >= num)
        hi = mid;
      else
        lo = mid + 1;
    }
    return hi * hi == num;
  }
};