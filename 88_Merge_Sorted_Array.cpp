//
//  88. Merge Sorted Array.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    if(n == 0) return;
    if(m == 0){
        
        nums1.resize(n);
        
        for(int i = 0; i < n; ++i){
            
            nums1[i] = nums2[i];
            
        }
        
        return;
        
    }
    
    nums1.resize(m);
    nums2.resize(n);
    //nums1.resize(m + n);
    
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    
}