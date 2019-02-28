/**
 * Very hard, stack.
 * See https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
 *
 * Keep ascending stack. Value at each position calculated when pop().
 *
 * Stack record indices, not values. Values can be easily looked up in array.
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (!s.empty() && heights[s.top()] > heights[i]) {
        int height = heights[s.top()];
        s.pop();
        int width = i - (s.empty() ? 0 : (s.top() + 1));
        if (width * height > maxArea) maxArea = width * height;
      }
      s.push(i);
    }
    while (!s.empty()) {
      int height = heights[s.top()];
      s.pop();
      int width = heights.size() - (s.empty() ? 0 : (s.top() + 1));
      if (width * height > maxArea) maxArea = width * height;
    }
    return maxArea;
  }
};

int main() {
  vector<int> a = {2, 4};
  int b = Solution().largestRectangleArea(a);
  cout << b << endl;
  return 0;
}