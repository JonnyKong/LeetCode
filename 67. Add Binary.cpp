//
//  67. Add Binary.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

string Solution::addBinary(string a, string b){
    
    int diff;
    
    int length;
    
    if(a.length() > b.length()){
        
        diff = a.length() - b.length();
        
        string temp(diff, '0');
        
        length = a.length();
        
        b.insert(0, temp);
        
    }
    
    else if(b.length() > a.length()){
        
        diff = b.length() - a.length();
        
        string temp(diff, '0');
        
        length = b.length();
        
        a.insert(0, temp);
        
    }
    
    else length = a.length();
    
    string result(length + 1, 0);
    
    for(int i = length; i>0; --i){
        
        result[i] += a[i-1] + b[i-1] - 96;
        
        if(result[i] == 2 || result[i] == 3){
            
            result[i] -= 2;
            
            ++result[i-1];
            
        }
        
    }
    
    for(int i=0; i < length + 1; ++i) result[i] += 48;
    
    if(result[0] == 48) return result.substr(1, length);
    
    else return result;
    
}