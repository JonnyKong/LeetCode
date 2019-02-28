//
//  278. First Bad Version.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isBadVersion(int version);

// binary search
int firstBadVersion(int n) {
  int left = 0, right = n, mid;

  while (left < right) {
    mid = left + ((right - left) >> 1);

    if (isBadVersion(mid))
      right = mid;

    else
      left = mid + 1;
  }

  return left;
}