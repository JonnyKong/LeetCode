//
//  4.Median of Two Sorted Arrays.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

double median(vector<int> numbers){
    
    if(numbers.size() % 2) return numbers[numbers.size() / 2];
    else return (double)(numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]) / 2;
    
}

//a new vector<int> is created. integers in nums1 and nums2 are moved to this new vector in ascending order
//the new vector is returned as the result

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    if(nums1.empty()) return median(nums2);
    else if(nums2.empty()) return median(nums1);
    
    vector<int> numbers;
    numbers.resize(nums1.size() + nums2.size());
    
    vector<int>::iterator p = nums1.begin();
    vector<int>::iterator q = nums2.begin();
    
    int i = 0;
    
    while(p != nums1.end() && q != nums2.end()){
        
        if(*p < *q) numbers[i++] = *p++;
        
        else numbers[i++] = *q++;
        
    }
    
    
    if(p == nums1.end() && q == nums2.end());
    
    else if(p == nums1.end()){
        
        while(q != nums2.end()){
            
            numbers[i++] = *q++;
            
        }
        
    }
    
    else if(q == nums2.end()){
        
        while(p != nums1.end()){
            
            numbers[i++] = *p++;
            
        }
        
    }
    
    if(i % 2) return numbers[i / 2];
    
    else return (double)(numbers[i / 2] + numbers[i / 2 - 1]) / 2;
    
}