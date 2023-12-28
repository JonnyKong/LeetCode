//
//  215. Kth Largest Element in an Array.h
//
//
//  Created by Jonny Kong on 3/3/16.
//
//

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() - k];
  }
};

// 2023-12-27
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums) {
            if (pq.size() >= k) {
                if (n >= pq.top()) {
                    pq.pop();
                    pq.push(n);
                }
            } else {
                pq.push(n);
            }
        }
        return pq.top();
    }
};