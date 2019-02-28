//
//  11. Container With Most Water.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

/*
 Q: Given n non-negative integers a1, a2, ..., an, where each represents a point
 at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 forms a container, such that the container contains the most water.

 This solution can be considered as traversing, with many cases skipped.

 Set two integers as boundaries, and move them towards each other until they
 meet, and return the optimal solution among all results.

 Suppose height[i] < height[j], the result is determined by height[i], which has
 no relevance with height[j]. For this specific i, any move of j would decrease
 the result. Thus we skip all related cases by ++i.

*/

int maxArea(vector<int>& height) {
  int i = 0, j = height.size() - 1;
  int result = abs((i - j) * min(height[i], height[j]));
  int diff = height.size() - 1;

  while (i < j) {
    if (height[i] < height[j]) {
      if ((j - i) * min(height[i], height[j]) > result) {
        result = diff * height[i];
      }

      ++i;

    }

    else {
      if ((j - i) * min(height[i], height[j]) > result) {
        result = (j - i) * height[j];
      }

      --j;
    }

    --diff;
  }

  return result;
}