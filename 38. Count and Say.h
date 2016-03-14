//
//  38. Count and Say.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

string next(string & a){
    
    string result;
    
    char temp[7] = "000000";
    
    int time = 1;
    
    int i;
    
    for(i = 0; i < a.length() - 1; ++i){
        
        if(a[i] == a[i + 1]) ++time;
        
        else{   //a change
            
            sprintf(temp, "%d", time);
            
            result += temp;
            
            sprintf(temp, "%d", a[i] - 48);
            
            result += temp;
            
            time = 1;
            
        }
        
    }
    
    sprintf(temp, "%d", time);
    
    result += temp;
    
    sprintf(temp, "%d", a[i] - 48);
    
    result += temp;
    
    return result;
    
}

string countAndSay(int n) {
    
    string result = "1";
    
    if(n == 1) return result;
    
    else{
        
        for(int i = 1; i < n; ++i){
            
            result = next(result);
            
        }
        
    }
    
    return result;
    
}