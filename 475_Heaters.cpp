/**
 * Trivial.
 *
 * Have some details. Beware of duplications, so use while instead of if.
 */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> l(houses.size(),
                  INT_MAX); /* Distance to closest left side heater */
    vector<int> r(houses.size(),
                  INT_MAX); /* Distance to closest right side heater */

    for (int i = 0, j = -1; i < houses.size(); ++i) {
      while (j + 1 < heaters.size() &&
             houses[i] >= heaters[j + 1]) /* If -> While */
        ++j;
      if (j >= 0) l[i] = houses[i] - heaters[j];
    }
    for (int i = houses.size() - 1, j = heaters.size(); i >= 0; --i) {
      while (j - 1 >= 0 && houses[i] <= heaters[j - 1]) --j;
      if (j < heaters.size()) r[i] = heaters[j] - houses[i];
    }

    int result = 0;
    for (int i = 0; i < houses.size(); ++i)
      result = max(result, min(r[i], l[i]));

    return result;
  }
};

/**
 * Solution2: Use binary search
 */

class Solution2 {
 private:
  int binarySearch(const vector<int>& stores, int target) {
    if (target < stores[0]) return -1;

    int l = 0, r = stores.size() - 1;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      int mid_value = stores[mid];
      if (mid_value <= target)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }

 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    for (int i = 0; i < houses.size(); ++i) {
      int pos_l = binarySearch(heaters, houses[i]), pos_r;
      if (heaters[pos_l] == houses[i])
        pos_r = pos_l;
      else if (pos_l + 1 < heaters.size())
        pos_r = pos_l + 1;
      else
        pos_r = -1;

      int radius_cur;
      if (pos_l >= 0 && pos_r >= 0)
        radius_cur =
            min(houses[i] - heaters[pos_l], heaters[pos_r] - houses[i]);
      else if (pos_l >= 0)
        radius_cur = houses[i] - heaters[pos_l];
      else
        radius_cur = heaters[pos_r] - houses[i];

      radius = radius_cur > radius ? radius_cur : radius;
    }
    return radius;
  }
};

int main() {
  vector<int> houses = {1, 1, 1, 1, 1, 1, 999, 999, 999, 999, 999};
  vector<int> heaters = {499, 500, 501};
  int r = Solution().findRadius(houses, heaters);
  cout << r << endl;
  return 0;
}