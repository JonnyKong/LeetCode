//
//  190. Reverse Bits.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

uint32_t reverseBits(uint32_t n) {
  unsigned int result = 0;

  unsigned int a = 1, b = 1;
  a <<= 31;

  while (a) {
    if (b & n) result |= a;
    a >>= 1;
    b <<= 1;
  }

  return result;
}