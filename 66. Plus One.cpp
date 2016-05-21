//
//  66. Plus One.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

vector<int> plusOne(vector<int>& digits) {
    
    ++digits[digits.size() - 1];
    
    for(int i = digits.size() - 1; i > 0; --i){
        
        if(digits[i] == 10) { digits[i] = 0; ++digits[i - 1]; }
        
    }
    
    if(digits[0] == 10){
        
        digits[0] = 0;
        
        digits.insert(digits.begin(), 1);
        
    }
    
    return digits;
    
}