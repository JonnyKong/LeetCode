class Solution {
  vector<int> org;

 public:
  Solution(vector<int> nums) { org = nums; }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return org; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result = org;
    for (int i = 0; i < result.size(); ++i) {
      int pos = rand() % (result.size() - i);
      int temp = result[i];
      result[i] = result[i + pos];
      result[i + pos] = temp;
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */