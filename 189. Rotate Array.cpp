//
//  189. Rotate Array.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void rotate(vector<int>& nums, int k) {
    
    if(nums.size() == 1) return;
    
    int size = nums.size();
    
    while(k >= size) k -= size;
    
    nums.insert(nums.begin(), nums.end() - k, nums.end());
    nums.resize(size);
    
}