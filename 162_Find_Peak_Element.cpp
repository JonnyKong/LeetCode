/**
 * Messy binary search
 */

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    /* Sanity check */
    if (nums.size() == 1)
      return 0;
    else if (nums.size() == 2)
      return nums[0] > nums[1] ? 0 : 1;

    /* Binary search */
    int lo = 0, hi = nums.size() - 1;
    int ans = -1;
    while (1) {
      int mid = lo + (hi - lo) / 2;
      if (mid == 0 || mid == nums.size() - 1) {
        ans = mid;
        break;
      }
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
        ans = mid;
        break;
      } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 0)
      return -1;
    else if (nums.size() == 1)
      return 0;
    else if (nums.size() == 2)
      return nums[0] > nums[1] ? 0 : 1;

    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
        l = mid + 1;
      else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
        r = mid - 1;
      else if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
        return mid;
      else
        r = mid - 1;
    }
    return l;
  }
};

// 2024-01-07
class Solution2 {
/**
 * Gradient ascent.
 */
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        // Handle special case: first or last is peak
        if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }

        int l = 1;
        int r = nums.size() - 2;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else if (nums[mid - 1] > nums[mid]) {
                r = mid - 1;
            }
        }

        return l;
    }
};


int main() {
  vector<int> a = {3, 4, 3, 2, 1};
  int b = Solution().findPeakElement(a);
  cout << b << endl;
}