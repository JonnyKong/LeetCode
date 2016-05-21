//
//  219. Contains Duplicate II.h
//  Project 1
//
//  Created by Jonny Kong on 3/3/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(nums.size() < 2) return 0;
        
        set<int> a;
        
        for(int i = 0; i < (k > nums.size() ? nums.size() : k); ++i){
            
            if(a.find(nums[i]) != a.end()) return 1;
            
            else{
                
                a.insert(nums[i]);
                
            }
            
        }
        
        for(int j = k, i = 0; j < nums.size(); ++i, ++j){
            
            if(a.find(nums[j]) != a.end()) return 1;
            
            else a.insert(nums[j]);
            
            a.erase(nums[i]);
            
        }
        
        return 0;
        
    }
};