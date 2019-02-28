//
//  231. Power of Two.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isPowerOfTwo(int n) {
  if (n <= 0) return 0;

  int a = 1;

  while (a) {
    if (n == a) return 1;

    a <<= 1;
  }

  return 0;
}