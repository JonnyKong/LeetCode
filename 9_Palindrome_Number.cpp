//
//  9. Palindrome Number.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isPalindrome(int x) {
  if (x < 0)
    return 0;
  else if (x < 10)
    return 1;
  else if (x == 10)
    return 0;

  int a = 1, b = 10;  // a starting from the left, b from the right
  while (x / a > 9) a *= 10;

  int power = 0;

  int big, small;

  while (a >= b) {
    big = x / a;
    small = x % b;

    if (big * pow(10, power++) != small) return 0;  // not equal

    x -= a * big;
    a /= 10;
    x -= small;
    b *= 10;
  }

  return 1;
}