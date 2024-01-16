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

// 2024-01-16
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        int cursor = 0;
        while (true) {
            for (int i = 0; i < strs.size() - 1; i++) {
                if (cursor >= strs[i].length()
                        || cursor >= strs[i + 1].length()
                        || strs[i][cursor] != strs[i + 1][cursor]) {
                    return strs[i].substr(0, cursor);
                }
            }
            cursor++;
        }
    }
};