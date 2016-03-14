//
//  154. Find Minimum in Rotated Sorted Array II.h
//  
//
//  Created by Jonny Kong on 2/29/16.
//
//

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        for(int i = 0; i < nums.size() - 1; ++i) if(nums[i] > nums[i + 1]) return nums[i + 1];
        
        return nums[0];
        
    }
};