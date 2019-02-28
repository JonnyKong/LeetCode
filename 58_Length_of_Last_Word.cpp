//
//  58. Length of Last Word.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int lengthOfLastWord(string s) {
  if (s.empty()) return 0;

  int result = 0;

  int i;

  for (i = s.length() - 1; s[i] == ' '; --i)

    if (i == 0) return 0;

  for (; s[i] != ' ' && i >= 0; --i, ++result)
    ;

  return result;
}