//
//  335. Self Crossing.h
//  Project 1
//
//  Created by Jonny Kong on 2/23/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

/*
 Very messy. No value of reference.
 
 Create a large mesh grid. Starting from the beginning, mark every point if passed. Passing a point more than one time returns 1;
 
 In order to keep within the memory limit, the size of the grid would be reduced, considering that the chances of reaching the outskirts of the grid is relatively small.
 
 Lucky guess

*/

bool isSelfCrossing(vector<int>& x) {
    
    int range = 0;
    
    for(int i = 0; i < x.size(); ++i){
        
        range += x[i];
        
    }
    
    int m, n;
    
    vector<vector<bool>> a;
    
    if(range >= 30){
        
        a.resize(range / 3);
        
        for(int i = 0; i < range / 3; ++i){
            
            a[i].resize(range / 3);
            
        }
        
        m = range / 6, n = range / 6;
        
    }
    
    else{
        
        a.resize(range * 2 + 1);
        
        for(int i = 0; i < range * 2 + 1; ++i){
            
            a[i].resize(range * 2 + 1);
            
        }
        
        m = range, n = range;
        
    }
    
    int condition = 0; //0, 1, 2, 3
    a[m][n] = 1;
    
    for(int i = 0; i < x.size(); ++i){
        
        if(condition == 0){
            
            for(int j = 0; j < x[i]; ++j){
                
                ++n;
                
                if(a[m][n]) return 1;
                
                else a[m][n] = 1;
                
            }
            
        }
        
        else if(condition == 1){
            
            for(int j = 0; j < x[i]; ++j){
                
                --m;
                
                if(a[m][n]) return 1;
                
                else a[m][n] = 1;
                
            }
            
        }
        
        else if(condition == 2){
            
            for(int j = 0; j < x[i]; ++j){
                
                --n;
                
                if(a[m][n]) return 1;
                
                else a[m][n] = 1;
                
            }
            
        }
        
        else if(condition == 3){
            
            for(int j = 0; j < x[i]; ++j){
                
                ++m;
                
                if(a[m][n]) return 1;
                
                else a[m][n] = 1;
                
            }
            
        }
        
        ++condition;
        
        if(condition == 4) condition = 0;
        
    }
    
    return 0;
    
}