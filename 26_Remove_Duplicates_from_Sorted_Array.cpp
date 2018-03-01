//	LeetCode Problem
//  26. Remove Duplicates from Sorted Array.h
//
//  Created by Zhaoning Kong on 1/22/18.
//  Copyright © 2018 Zhaoning Kong. All rights reserved.
//

class Solution {
public:
    int removeDuplicates(vector<int> & nums) {
        
        // Sanity check
        if(nums.empty()) return 0;

        // Construct iterator
        auto slow = nums.begin();
        auto fast = nums.begin();
        
        // Traverse the whole list
        while(1) {
            while((fast - nums.begin()) + 1 < nums.size() && *fast == *(fast + 1)) {
                *(slow++) = *(fast++);
            }
            if((fast - nums.begin()) == nums.size()) {
                return slow - nums.begin();
            }
        }
    }
};