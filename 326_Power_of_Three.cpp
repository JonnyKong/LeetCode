//
//  326. Power of Three.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isPowerOfThree(int n) {
  int i = 0;
  for (int i = 0; i < 30; i++) {
    if (n == pow(3, i)) return 1;
  }
  return 0;
}