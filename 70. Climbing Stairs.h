//
//  70. Climbing Stairs.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int climbStairs(int n) {
    
    if(n == 1) return 1;
    
    else if(n == 2) return 2;
    
    else{
        
        int* p = new int[n];
        
        p[0] = 1; p[1] = 2;
        
        for(int i = 2; i < n; ++i){
            
            p[i] = p[i - 1] + p[i - 2];
            
        }
        
        int result =  p[n - 1];
        delete [] p;
        return result;
        
    }
}