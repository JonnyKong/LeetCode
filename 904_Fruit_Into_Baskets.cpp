/**
 * Sliding window. O(n).
 * https://leetcode.com/problems/fruit-into-baskets/discuss/170745/Problem%3A-Longest-Subarray-With-2-Elements
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    int a = -2, b = -1;
    int result = 0, result_cur = 0;
    int count_b = 0;
    for (int i = 0; i < tree.size(); ++i) {
      if (tree[i] == b) {
        ++result_cur;
        ++count_b;
      } else if (tree[i] == a) {
        ++result_cur;
        count_b = 1;
        a = b;
        b = tree[i];
      } else {
        result_cur = count_b + 1;
        count_b = 1;
        a = b;
        b = tree[i];
      }
      result = result_cur > result ? result_cur : result;
    }
    return result;
  }
};

int main(int argc, const char* argv[]) {
  vector<int> a = {1, 0, 1, 4, 1, 4, 1, 2, 3};
  int b = Solution().totalFruit(a);
  cout << b << endl;
  return 0;
}
