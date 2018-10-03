/**
 * O(n) greedy & DP;
 * 
 * DP: maintain 2 dp arrays. See comments in code.
 * 
 * Greedy: For example, if nums[i] > nums[i - 1], then up[i] = up[i - 1], this
 * is because nums[i] > nums[i - 1] > <whatever previous down number is>.
 */

class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {

        /* DP array. The longest sequence ending at i with the last number 
         * up / down. 
         * It can be seen that up and down only increases. So only return the
         * last element. */
        int *up = new int[nums.size()];
        int *down = new int[nums.size()];
        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }

        int result = up[nums.size() - 1] > down[nums.size() - 1] ? 
            up[nums.size() - 1] : down[nums.size() - 1];

        free(up);
        free(down);
        return result;
        
    }
};
