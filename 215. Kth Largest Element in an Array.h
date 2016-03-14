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