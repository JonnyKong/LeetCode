//
//  5.Longest Palindromic Substring.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

// This algorithm is based on dynamic programming.
// A vector<vector<bool>> records whether the substring of m and n is
// palindrome. If a substring is palindrome, then --m and ++n, and verify if s[m]
// == s[n].

string longestPalindrome(string s) {
  int length = s.length();
  if (!length) return 0;
  // if(length == 1) return s;
  // else if(length == 2) if(s[0] == s[1]) return s;

  int lengthMax = 0;
  // string result;
  int left = 0, right = 0;  // left and right boundary for substring
  int m, n;
  int i;

  vector<vector<bool>> numbers(length, vector<bool>(length, 0));
  /*
   numbers.resize(length);
   for(int i = 0; i < length; ++i) numbers[i].resize(length - i);
   */
  for (i = 0; i < length; ++i) {
    numbers[i][i] = 1;

    if (lengthMax < 1) {
      lengthMax = 1;

      left = i;

      right = i;
    }
  }

  for (i = 1; i < length - 1; ++i) {
    m = i - 1, n = i + 1;

    if (numbers[i][i]) {
      while (m >= 0 && n < length) {
        if (s[m] == s[n]) {
          numbers[m][n] = 1;

          if (n - m + 1 > lengthMax) {
            lengthMax = n - m + 1;

            left = m;

            right = n;
          }

          --m;
          ++n;

        }

        else {
          //--m; ++n;

          break;
        }
      }
    }

    // while(m >= 0 && n < length) numbers[m--][n++] = 0;
  }

  for (i = 0; i < length - 1; ++i) {
    if (s[i] == s[i + 1]) {
      numbers[i][i + 1] = 1;

      if (lengthMax < 2) {
        lengthMax = 2;

        left = i;

        right = i + 1;
      }
    }

    // else numbers[i][i + 1] = 0;
  }

  for (i = 1; i < length - 2; ++i) {
    m = i - 1, n = i + 2;

    if (numbers[i][i + 1]) {
      while (m >= 0 && n < length) {
        if (s[m] == s[n]) {
          numbers[m][n] = 1;

          if (n - m + 1 > lengthMax) {
            lengthMax = n - m + 1;

            left = m;

            right = n;
          }

          --m;
          ++n;

        }

        else {
          //--m; ++n;

          break;
        }
      }
    }

    // while(m >= 0 && n < length) numbers[m--][n++] = 0;
  }

  return s.substr(left, right - left + 1);
}