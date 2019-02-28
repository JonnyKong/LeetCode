/**
 * O(n) BFS & greedy.
 *
 * Suppose the range of current jump is [curBegin, curEnd], maxReach is the
 * farthest point that all points in [curBegin, curEnd] can reach.
 *
 * Then, it takes n jumps to reach any point in [curBegin, curEnd], and takes
 * (n + 1) jumps to reach any point in [curEnd + 1, maxReach]. This idea is
 * similar to that of BFS.
 *
 * So, we can traverse the array in O(n). When we reach curEnd, it means we are
 * transiting to the next region. Thus increment jump, and update curEnd to
 * maxReach.
 */

class Solution {
 public:
  int jump(vector<int>& nums) {
    int maxReach = 0, curEnd = 0, jumps = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      maxReach = (i + nums[i]) > maxReach ? (i + nums[i]) : maxReach;
      if (i == curEnd) { /* Enters next level of BFS */
        curEnd = maxReach;
        ++jumps;
      }
    }
    return jumps;
  }
};