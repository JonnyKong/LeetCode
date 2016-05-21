//
//  125. Valid Palindrome.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isPalindrome(string s) {
    
    int i = 0, j = s.length() - 1;
    
    while(i < j){
        
        while(a[i] == ' ') ++i; //stepping over spaces;
        while(a[j] == ' ') --j;
        
        if(a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
        if(a[j] >= 'A' && a[j] <= 'Z') a[i] += 32;
        
    }
    
}