//
//  187. Repeated DNA Sequences.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

/*
 
 This algorithm is implemented by hash table.
 
*/

class Solution {
public:
    
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> result;
        
        if(s.length() <= 10) return result;
        
        unordered_map<int, bool> listed;
        
        int hash = 0;
        
        for(int i = 0; i < 10; ++i){
            
            hash <<= 2;
            
            if(s[i] == 'C') hash += 1;
            
            else if(s[i] == 'G') hash += 2;
            
            else if(s[i] == 'T') hash += 3;
            
        }
        
        listed[hash] = 0;
        
        for(int i = 0; i < s.length() - 10; ++i){
            
            if(s[i] == 'C') hash -= 262144;
            
            else if(s[i] == 'G') hash -= 524288;
            
            else if(s[i] == 'T') hash -= 786432;
            
            hash <<= 2;
            
            if(s[i + 10] == 'A');
            
            else if(s[i + 10] == 'C') hash += 1;
            
            else if(s[i + 10] == 'G') hash += 2;
            
            else if(s[i + 10] == 'T') hash += 3;
            
            if(listed.find(hash) == listed.end()) listed[hash] = 0;
            
            else{
                
                if(!listed[hash]){
                    
                    result.push_back(s.substr(i + 1, 10));
                    
                    listed[hash] = 1;
                    
                }
                
            }
            
        }
        
        return result;
        
    }
    
};