//
//  6. ZigZag Conversion.h
//
//
//  Created by Jonny Kong on 3/4/16.
//
//

/*

 Pure maths.

*/

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) return s;

    string result;

    for (int i = 0; i < s.length(); i += 2 * (numRows - 1)) result += s[i];

    for (int i = 0; i < numRows - 2; ++i) {
      int diff = (numRows - 1) - 2 * (i + 1);

      bool sign = 1;

      result += s[i + 1];

      for (int j = i + numRows; j + sign * diff < s.length();
           j += (numRows - 1)) {
        result += s[j + sign * diff];

        sign ^= 1;
      }
    }

    for (int i = numRows - 1; i < s.length(); i += 2 * (numRows - 1))
      result += s[i];

    return result;
  }
};