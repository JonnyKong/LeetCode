//
//  162. Find Peak Element.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if(nums[1] < nums[0]) return 0;
        
        else if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        
        for(int i = 1; i < nums.size() - 1; ++i){
            
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
            
        }
        
    }
};