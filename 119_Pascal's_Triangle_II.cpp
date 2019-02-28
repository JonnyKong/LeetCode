//
//  119. Pascal's Triangle II.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

vector<int> Solution::getRow(int rowIndex) {
  rowIndex++;

  vector<int> result;

  result.push_back(1);

  unsigned int j = 0;

  for (int i = rowIndex - 1; i > 0; --i) {
    result.push_back((int)((long)(result[j]) * i / (rowIndex - i)));

    ++j;
  }

  return result;
}