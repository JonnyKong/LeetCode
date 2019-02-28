//
//  290. Word Pattern.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool wordPattern(string pattern, string str) {
  int number = pattern.length();

  vector<string> strings;
  vector<string> have;

  int position;
  int length = 0;

  for (int i = 0; i < str.length(); ++i) {
    if (str[i] == ' ') {
      position = i;

      strings.push_back(str.substr(i - length, length));

      length = 0;

    }

    else
      ++length;
  }

  strings.push_back(str.substr(str.length() - length, length));

  if (number != strings.size()) return 0;

  bool* checked = new bool[number];

  while (1) {
    int i;

    for (i = 0; i < number; ++i) {  // if all is checked, then return true

      if (!checked[i]) break;

      if (i == number - 1) {  // check if repeat

        for (int i = 0; i < have.size(); ++i) {
          for (int j = i + 1; j < have.size(); ++j) {
            if (have[i] == have[j]) return 0;
          }
        }

        return 1;
      }
    }

    char temp = pattern[i];
    int tempPosition = i;
    checked[i] = 1;
    have.push_back(strings[i]);

    ++i;

    for (; i < number; ++i) {
      if (pattern[i] == temp) {
        if (strings[i] != strings[tempPosition]) return 0;

        checked[i] = 1;
      }
    }
  }
}