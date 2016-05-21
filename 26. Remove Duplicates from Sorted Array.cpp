//
//  26. Remove Duplicates from Sorted Array.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int removeDuplicates(vector<int>& nums) {
    
    if(nums.empty()) return 0;
    
    vector<int>::iterator slow = nums.begin();
    vector<int>::iterator fast = nums.begin();
    ++slow;
    ++fast;
    int current = nums[0];
    int result = 1;
    
    while(fast != nums.end()){
        
        if(*fast != current){
            
            current = *fast;
            *slow++ = *fast++;
            ++result;
            
        }
        
        else ++fast;
        
    }
    
    return result;
    
}