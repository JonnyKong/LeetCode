/* Upon detecting decrease sequence in array, check for all two possibilities.
 * Either increase first element, or decrease second element.
 */

class Solution {
    public boolean checkPossibility(int[] nums) {
        int desc_cnt = 0;
        for(int i = 0; i < nums.length - 1; ++i) {
            if(nums[i] > nums[i + 1]) {
                if(desc_cnt > 0) {
                    return false;    
                }
                desc_cnt += 1;
                /* Check for possible substitutions */
                /* Increase 2nd number */
                if(i + 2 == nums.length || nums[i + 2] >= nums[i]) {
                    continue;   
                }
                /* Decrease 1st number */
                if(i == 0 || nums[i - 1] <= nums[i + 1]) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }
}
