//
//  50. Pow(x, n).h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

#include <iostream>
using namespace std;

double myPow(double x, int n) {
  if (!n) return 1;

  int sign = 1;
  int sign1 = 1;
  if (n <= 0) {
    sign1 *= -1;
    n *= -1;
  }
  if (x <= 0) {
    x *= -1;

    if (n % 2 != 0) sign *= -1;
  }

  if (x == 1.0) return sign;

  double result = x;

  for (int i = 0; i < n - 1; ++i) {
    result *= x;

    if (result == 0) return 0;
  }

  if (sign1 > 0)
    return result * sign;
  else
    return 1 / (result * sign);
}

class Solution2 {
 public:
  double myPow(double x, int n) {
    if (n == 0)
      return 1;
    else if (n == 1)
      return x;
    else if (n % 2 == 0) {
      double tmp = myPow(x, n / 2);
      return tmp * tmp;
    } else {
      double tmp = myPow(x, n / 2);
      if (n > 0)
        return tmp * tmp * x;
      else
        return tmp * tmp / x;
    }
  }
};

int main() {
  double result = Solution2().myPow(2.1, 3);
  cout << result << endl;
}