//
//  14. Longest Common Prefix.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

string longestCommonPrefix(vector<string>& strs) {
  string temp = "";

  if (strs.empty()) return temp;

  temp = strs[0];

  for (int i = 1; i < strs.size(); ++i) {
    for (int j = 0; j < temp.length(); ++j) {
      if (temp[j] != strs[i][j] || j == strs[i].size()) {
        temp = temp.substr(0, j);
        continue;
      }
    }
  }

  return temp;
}