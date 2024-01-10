//
//  88. Merge Sorted Array.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  if (n == 0) return;
  if (m == 0) {
    nums1.resize(n);

    for (int i = 0; i < n; ++i) {
      nums1[i] = nums2[i];
    }

    return;
  }

  nums1.resize(m);
  nums2.resize(n);
  // nums1.resize(m + n);

  nums1.insert(nums1.end(), nums2.begin(), nums2.end());
  sort(nums1.begin(), nums1.end());
}

// 2024-01-09
class Solution2 {
public:
  // Two pointers. Since every number of num1 will always be moved back zero or
  // more positions, traverse from back to front, so write to an num1 element is
  // always after read, gives O(1) space
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    nums1.resize(m + n);
    int p1 = m - 1;
    int p2 = n - 1;

    for (int i = m + n - 1; i >= 0; i--) {
      if (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
          nums1[i] = nums1[p1--];
        } else {
          nums1[i] = nums2[p2--];
        }
      } else if (p1 >= 0) {
        nums1[i] = nums1[p1--];
      } else {
        nums1[i] = nums2[p2--];
      }
    }
    }
};