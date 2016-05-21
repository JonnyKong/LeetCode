//
//  20. Valid Parentheses.h
//  Project 1
//
//  Created by Jonny Kong on 2/29/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> p;
        
        for(int i = 0; i < s.length(); ++i){
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                
                p.push(s[i]);
                
            }
            
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                
                if(p.empty()) return 0;
                
                if(s[i] == ')'){
                    
                    if(p.top() == '(');
                    
                    else return 0;
                    
                }
                
                else if(s[i] == ']'){
                    
                    if(p.top() == '[');
                    
                    else return 0;
                    
                }
                
                else if(s[i] == '}'){
                    
                    if(p.top() == '{');
                    
                    else return 0;
                    
                }
                
                p.pop();
                
            }
            
        }
        
        if(!p.empty()) return 0;
        
        else return 1;
        
    }
};