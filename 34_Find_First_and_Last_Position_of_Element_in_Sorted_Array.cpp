#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int searchLowerBound(const vector<int> &nums, int target);
  int searchUpperBound(const vector<int> &nums, int target);

 public:
  vector<int> searchRange(vector<int> &nums, int target);
};

int Solution::searchLowerBound(const vector<int> &nums, int target) {
  int ans = -1;
  int lo = 0, hi = nums.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int midValue = nums[mid];
    if (midValue < target) {
      ans = mid;
      lo = mid + 1;
    } else if (midValue > target) {
      hi = mid - 1;
    } else if (midValue == target) {
      hi = mid - 1;
    }
  }
  return ans;
}
int Solution::searchUpperBound(const vector<int> &nums, int target) {
  int ans = nums.size();
  int lo = 0, hi = nums.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int midValue = nums[mid];
    if (midValue < target) {
      lo = mid + 1;
    } else if (midValue > target) {
      ans = mid;
      hi = mid - 1;
    } else if (midValue == target) {
      lo = mid + 1;
    }
  }
  return ans;
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
  vector<int> result;

  int lo = searchLowerBound(nums, target) + 1;
  int hi = searchUpperBound(nums, target) - 1;
  if (lo >= 0 && hi < nums.size() && nums[lo] == target && nums[hi] == target) {
    result.push_back(lo);
    result.push_back(hi);
  } else {
    result.push_back(-1);
    result.push_back(-1);
  }
  return result;
}

class Solution2 {
 private:
  int searchUpper(vector<int> &nums, int target) {
    int l = -1, r = nums.size();
    while (l < r) {
      int mid = l + (r - l) / 2;
      int midValue = nums[mid];
      if (midValue <= target)
        l = mid + 1;
      else
        r = mid;
    }
    return r - 1;
  }
  int searchLower(vector<int> &nums, int target) {
    int l = -1, r = nums.size();
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      int midValue = nums[mid];
      if (midValue < target)
        l = mid;
      else
        r = mid - 1;
    }
    return l + 1;
  }

 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result;
    if (nums.empty()) {
      result.push_back(-1);
      result.push_back(-1);
      return result;
    }

    int l = searchLower(nums, target);
    int r = searchUpper(nums, target);
    if (nums[l] == target && nums[r] == target) {
      result.push_back(l);
      result.push_back(r);
    } else {
      result.push_back(-1);
      result.push_back(-1);
    }
    return result;
  }
};

int main() {
  vector<int> a = {5, 7, 7, 8, 8, 10};
  vector<int> b = Solution().searchRange(a, 8);
  cout << b[0] << endl << b[1] << endl;
}