/**
 * Key observation:
 * 1) Make 1-1 inverse array of flowers
 * 2) Use greedy: See comments below.
 *  We have to find a region a[i] ... a[i + k + 1] where every element between
 *  i and i+k+1 are larger than a[i] and a[i + k + 1]. If we found one element
 *  a[k] that does not satisfy, then a[i + 1] .. a[k - 1] cannot be candidate
 *  left boarders.
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int kEmptySlots(vector<int>& flowers, int k) {
    vector<int> days(flowers.size());
    for (int i = 0; i < flowers.size(); ++i) days[flowers[i] - 1] = i + 1;

    /* Greedy: We just need to find a subarray days[left, left+1,..., left+k-1,
     * right] which satisfies: for any i = left+1,..., left+k-1, we can have
     * days[left] < days[i] && days[right] < days[i]
     **/
    int l = 0, r = k + 1, i = 1;
    int result = INT_MAX;
    while (i < flowers.size()) {
      if (i == r) { /* Found one */
        result = min(result, max(days[l], days[r]));
      }
      if (days[i] < days[l] || days[i] < days[r]) { /* Invalid */
        l = i;
        r = i + k + 1;
      }
      ++i;
    }
    return result == INT_MAX ? -1 : result;
  }
};

int main() {
  vector<int> a = {1, 3, 2};
  int b = Solution().kEmptySlots(a, 1);
  cout << b << endl;
}