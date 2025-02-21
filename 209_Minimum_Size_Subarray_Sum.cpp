#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty()) return 0;
    int left = 0;
    int right = 0;  // included
    int sum = nums[0];
    int minLength = INT_MAX;
    while (sum < s) {
      sum += nums[++right];
      if (right == nums.size()) return 0;
    }
    if (sum > s) {
      while (sum > s) {
        sum -= nums[left++];
      }
      if (sum < s) sum += nums[--left];
    }

    minLength = right - left + 1;

    while (right + 1 < nums.size()) {
      sum += nums[++right];
      if (sum > s) {
        while (sum > s) {
          sum -= nums[left++];
        }
        if (sum < s) sum += nums[--left];
      }
      if (minLength > (right - left + 1)) minLength = (right - left + 1);
    }
    return minLength;
  }
};

// 2025-02-20
class Solution2 {
    // Two pointers: maintain floating window >= target
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (target <= 0) {
            return 0;
        }
        int i = 0; int j = 0;
        int sum = nums[0];

        // Find first satisfying window
        while (sum < target) {
            // Add in nums[j + 1]
            if (j + 1 == nums.size()) {
                // Even the largest window is smaller than target
                return 0;
            }
            sum += nums[j + 1];
            j++;
        }
        int minDist = j - i + 1;

        // Move the window
        while (true) {
            // printf("%d, %d\n", i, j);
            if (i + 1 <= j && sum - nums[i] >= target) {
                // First, try to remove nums[i]
                sum -= nums[i];
                i++;
            } else {
                // Then, try to add in nums[j + 1]
                if (j + 1 >= nums.size()) {
                    break;
                } else {
                    sum += nums[j + 1];
                    j++;
                }
            }
            minDist = min(minDist, j - i + 1);
        }
        return minDist;
    }
};