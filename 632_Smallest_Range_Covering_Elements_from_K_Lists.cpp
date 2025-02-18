#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    // Min-heap of <x, vec_idx, ele_idx>
    std::priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        pq;

    int curMax = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i][0], i, 0});
      curMax = max(curMax, nums[i][0]);
    }
    int bestMin = pq.top()[0];
    int bestMax = curMax;

    while (true) {
      auto top = pq.top();
      pq.pop();
      int x = top[0];
      int vec_idx = top[1];
      int ele_idx = top[2];

      if (ele_idx + 1 >= nums[vec_idx].size()) {
        break;
      } else {
        pq.push({nums[vec_idx][ele_idx + 1], vec_idx, ele_idx + 1});

        int curMin = pq.top()[0];
        curMax = max(curMax, nums[vec_idx][ele_idx + 1]);

        if (curMax - curMin < bestMax - bestMin) {
          bestMin = curMin;
          bestMax = curMax;
        }
      }
    }

    return {bestMin, bestMax};
  }
};
