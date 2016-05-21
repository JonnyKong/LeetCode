//
//  268. Missing Number.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int missingNumber(vector<int>& nums) {
    
    int length = nums.size();
    int i;
    
    bool* occupied = new bool[length + 1];
    memset(occupied, 0, length * sizeof(bool));
    
    for(i = 0; i < length; ++i){
        
        occupied[nums[i]] = 1;
        
    }
    
    int missingNumber;
    
    for(i = 0; i < length + 1; ++i){
        
        if(!occupied[i]) {missingNumber = i; break;}
        
    }
    
    delete [] occupied;
    
    return missingNumber;
    
}