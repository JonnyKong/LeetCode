//
//  242. Valid Anagram.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//


int compare(const void * a, const void * b){
    
    return (*(char*)(a) - *(char*)(b));
    
}

bool isAnagram(string s, string t) {
    
    if(s.length() == 1 && t.length() == 1) return s[0] == t[0];
    
    if(s.length() != t.length()) return 0;
    
    char a[s.length() + 1];
    
    char b[s.length() + 1];
    
    int i;
    
    for(i=0; i<s.length(); ++i){
        
        a[i] = s[i];
        
        b[i] = t[i];
        
    }
    
    a[i] = '\0';
    
    b[i] = '\0';
    
    qsort(a, s.length(), sizeof(char), compare);
    
    qsort(b, s.length(), sizeof(char), compare);
    
    if(strcmp(a, b) == 0) return 1;
    
    else return 0;
}