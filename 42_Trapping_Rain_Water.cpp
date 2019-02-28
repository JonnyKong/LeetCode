/**
 * Greedy / two pointers.
 *
 * Key observation: Add water by columns. Keep left and right max height.
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int result = 0;
    int maxLeft = 0, maxRight = 0;
    int l = 0, r = height.size() - 1;
    while (l <= r) {
      if (height[l] <= height[r]) {
        if (height[l] > maxLeft) maxLeft = height[l];
        result += maxLeft - height[l];
        ++l;
      } else {
        if (height[r] > maxRight) maxRight = height[r];
        result += maxRight - height[r];
        r--;
      }
    }
    return result;
  }
};

int main() {
  vector<int> a = {4, 1, 2};
  vector<int> b = {1, 3, 4, 2};
  vector<int> c = Solution().nextGreaterElement(a, b);
  for (int i : c) cout << i << " ";
  cout << endl;
  return 0;
}