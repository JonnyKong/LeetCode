#include <iostream>
#include <vector>
#include <deque>

using namespace std;


class Solution {
private:
    int searchLowerBound(const vector<int> &nums, int target);
    int searchUpperBound(const vector<int> &nums, int target);
public:
    vector<int> searchRange(vector<int>& nums, int target);
};

int Solution::searchLowerBound(const vector<int> &nums, int target) {
    int ans = -1;
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi) {
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
int Solution:: searchUpperBound(const vector<int> &nums, int target) {
    int ans = nums.size();
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi) {
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
    if(lo >= 0 && hi < nums.size() && nums[lo] == target && nums[hi] == target) {
        result.push_back(lo);
        result.push_back(hi);
    } else {
        result.push_back(-1);
        result.push_back(-1);
    }
    return result;
}


int main() {
    vector<int> a = {5,7,7,8,8,10};
    vector<int> b = Solution().searchRange(a, 8);
    cout << b[0] << endl << b[1] << endl;
}