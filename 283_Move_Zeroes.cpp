//
//  283. Move Zeroes.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void moveZeroes(vector<int>& nums) {
    
    vector<int>::iterator a = nums.begin();
    
    int i=0;
    
    while(a != nums.end()){
        
        if(*a == 0){
            
            ++i;
            
            nums.erase(a);
            
        }
        
        else ++a;
        
    }
    
    for(int j=0; j<i; ++j) nums.push_back(0);
    
}