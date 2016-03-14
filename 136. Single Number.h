//
//  136. Single Number.h
//  Project 1
//
//  Created by Jonny Kong on 3/1/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        for(int i = 1; i < nums.size(); ++i) nums[0] ^= nums[i];
        
        return nums[0];
        
    }
};