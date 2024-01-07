class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] > 0 && nums[i] <= nums.size() &&
             nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
  }
};

// 2024-01-04
class Solution2 {
public:
    int getFirstPositiveOrZero(const vector<int> & nums) {
        for (int n : nums) {
            if (n > 0) {
                return n;
            }
        }
        return 0;
    }

    void flipNonpositives(vector<int> & nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                nums[i] = target;
            }
        }
    }

    int firstMissingPositive(vector<int>& nums) {
        int firstPositive = getFirstPositiveOrZero(nums);
        if (firstPositive == 0) {
            // Means no positive seen
            return 1;
        }

        // Nonpositive numbers are useless, we set them to any positive number that exists in `nums`
        flipNonpositives(nums, firstPositive);
        nums.push_back(firstPositive);

        // Invert nums[i] to negative to denote that i exists
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) > 0 && abs(nums[i]) < nums.size()) {
                if (nums[abs(nums[i])] > 0) {
                    nums[abs(nums[i])] *= -1;
                }
            }
        }

        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] > 0){ 
                break;
            }
        }
        return i;
    }
};

/*
1 2 0
convert nonpositive to any positive: 1 2 1 (say 1)
i = 0: 1 -2 1 1
i = 1: 1 -2 -1 1
i = 2: 1 -2 -1 1

3 4 0 1:
convert zeros to any positive: 3 4 3 1 (say 3)
i = 0: 3 4 3 -1 3
i = 1: 3 4 3 -1 -3
i = 2: 3 4 3 -1 -3
i = 3: 3 -4 3 -1 -3
*/
