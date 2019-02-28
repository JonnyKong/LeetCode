class Solution {
 public:
  int integerBreak(int n) {
    if (n < 4) return n - 1;
    int num2 = n % 3;
    if (num2 == 1)
      num2 = 2;
    else if (num2 == 2)
      num2 = 1;
    int num3 = (n - 1) / 3 - num2 + 1;
    return pow(3, num3) * pow(2, num2);
  }
};