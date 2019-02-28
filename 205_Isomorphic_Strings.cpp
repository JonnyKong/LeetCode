//
//  205. Isomorphic Strings.h
//
//
//  Created by Jonny Kong on 2/28/16.
//
//

/*

 This algorithm is implemented by map. Two maps were set up to check if the two
 strings are isomorphic mutually.

*/

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return 0;

    unordered_map<char, char> a;
    unordered_map<char, char> b;

    for (int i = 0; i < s.length(); ++i) {
      if (a.find(s[i]) == a.end()) {  // a new key

        a[s[i]] = t[i];

      }

      else {
        if (a[s[i]] != t[i]) return 0;
      }

      if (b.find(t[i]) == b.end()) {
        b[t[i]] = s[i];

      }

      else {
        if (b[t[i]] != s[i]) return 0;
      }
    }

    return 1;
  }
};