//
//  3. Longest Substring Without Repeating Characters.h
//  
//
//  Created by Jonny Kong on 3/4/16.
//
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> hash;
        
        int current(0);
        int maxLength(0);
        
        int valid(0);
        
        for(int i = 0; i < s.length(); ++i){
            
            auto c = hash.find(s[i]);
            
            if(c == hash.end() || hash[s[i]] < valid){
                
                hash[s[i]] = i;
                
                ++current;
                
                maxLength = max(maxLength, current);
                
            }
            
            else{
                
                valid = hash[s[i]] + 1; //cut off
                
                hash[s[i]] = i;
                
                current = i - valid + 1;
                
            }
            
        }
        
        return maxLength;
        
    }
};