//
//  263. Ugly Number.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isUgly(int num) {
    
    if(num == 0) return 0;
    
    if(num == 1) return 1;
    
    while(num % 4 == 0) num >>= 2;
    
    while(num % 2 == 0) num >>= 1;
    
    while(num % 3 == 0) num /= 3;
    
    while(num % 5 == 0) num /= 5;
    
    return num == 1;
    
}