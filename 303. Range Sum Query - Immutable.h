//
//  303. Range Sum Query - Immutable.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//


//Because there are many calls to the function, so an array is created to save the results.
//The array is initialized in the constructor
class NumArray {
    
    vector<int> sums;
    
public:
    NumArray(vector<int> &nums);
    
    int sumRange(int i, int j);
};

Numarray::NumArray(vector<int> &nums) {
    
    if(nums.empty()) return;
    
    sums.resize(nums.size());
    
    sums[0] = nums[0];
    
    int size = nums.size();
    
    for(int i=1; i<size; ++i){
        
        sums[i] = sums[i - 1] + nums[i];
        
    }
    
}

int NumArray::sumRange(int i, int j) {
    
    return sums[j] - sums[i - 1];
    
}