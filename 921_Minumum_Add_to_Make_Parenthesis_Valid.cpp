#include <iostream>
#include <stack>

class Solution {
 public:
  int minAddToMakeValid(string S) {
    std::stack<char> s;
    int result = 0;
    for (int i = 0; i < S.length(); ++i) {
      if (S[i] == '(') {
        s.push('(');
      } else {
        if (!s.empty() && s.top() == '(') {
          s.pop();
        } else {
          result++;
        }
      }
    }
    result += s.size();
    return result;
  }
};