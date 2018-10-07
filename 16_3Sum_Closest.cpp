/**
 * Sorting + two_pointers.
 * 
 * Because it is guaranteed that each input would have exactly one solution, it
 *  simplifies to 15.3Sum with minor modifications. Just remember to deal with
 *  duplicates.
 */

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        assert(nums.size() >= 3);

        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int l = i + 1, r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(min_diff)) {
                    min_diff = sum - target;
                    if (min_diff == 0)   /* Pruning */
                        return target;
                }
                if (sum < target) {
                    while (l + 1 < nums.size() && nums[l] == nums[l + 1])
                        ++l;
                    ++l;
                } else {
                    while(r - 1 >= 0 && nums[r - 1] == nums[r])
                        --r;
                    --r;
                }
            }

            /* Deal with i duplicates in the end. Possible that nums[i] == nums[l] */
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        return min_diff + target;
    }
};


int main() {
    vector<int> a = {1,1,-1,-1,3};
    cout << Solution().threeSumClosest(a, 3) << endl;
    return 0;
}