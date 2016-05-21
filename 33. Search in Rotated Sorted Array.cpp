//
//  33. Search in Rotated Sorted Array.h
//  
//
//  Created by Jonny Kong on 3/3/16.
//
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int i = 0;
        
        for(int i = 0; i < nums.size() - 1; ++i){
            
            if(nums[i] > nums[i + 1]) break;
            
        }
        
        if(i == nums.size() - 1){
            
            if(find(nums.begin(), nums.end(), target) != nums.end()) return (find(nums.begin(), nums.end(), target) - nums.begin());
            
            else return -1;
            
        }
        
        if(find(nums.begin(), nums.begin() + i + 1, target) != nums.begin() + i + 1){   //in first subset
            
            return (find(nums.begin(), nums.begin() + i + 1, target) - nums.begin());
            
        }
        
        else if(find(nums.begin() + i, nums.end(), target) != nums.end()) return (find(nums.begin() + i, nums.end(), target) - nums.begin());
        
        else return -1;
        
    }
};