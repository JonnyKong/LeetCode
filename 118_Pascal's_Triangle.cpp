//
//  118. Pascal's Triangle.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> v(numRows);

  vector<vector<int>>::iterator a = v.begin();

  vector<int>::iterator b, m;

  for (int i = 0; i < numRows; ++i) {
    b = a[i].begin();

    if (i == 0) {
      a[i].push_back(1);

      continue;
    }

    m = a[i - 1].begin();  // get elements from last row

    for (int j = 0; j < i + 1; ++j) {
      if (j == 0 || j == i) {  // First or last element

        a[i].push_back(1);

      }

      else {
        a[i].push_back(*m + *(m + 1));

        m++;
      }
    }
  }

  return v;
}