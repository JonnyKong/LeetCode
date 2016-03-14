//
//  8. String to Integer (atoi).h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int Solution::myAtoi(string str){
    
    long result = 0;
    
    int sign = 1;
    
    string::iterator i = str.begin();
    
    while(*i == ' ') ++i;   //jump over spaces;
    
    if(*i == '-') { sign = -1; ++i; }
    
    else if(*i == '+') ++i;
    
    if(*i < 48 || *i >= 58 || i == str.end()) return 0;   //more than one sign, or nothing left
    
    while(*i == '0') ++i; //remaining 0s
    
    while(i != str.end()){
        
        if(*i >= 58 || *i < 48) break;
        
        result *= 10;
        
        result += *i++ - 48;
        
        if(sign == 1 && result > 2147483647) { result = 2147483647; break; }
        
        else if(sign == -1 && result > 2147483648) { result = 2147483648; break; }
        
    }
    
    return (int)result * sign;
    
}