//
//  27. Remove Element.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int removeElement(vector<int>& nums, int val) {
    
    vector<int>::iterator a = nums.begin();
    
    int length = 0;
    
    while(a != nums.end()){
        
        if(*a == val) nums.erase(a);
        
        else{
            
            ++length;
            
            ++a;
            
        }
        
    }
    
    return length;
    
}