//
//  172. Factorial Trailing Zeroes.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int trailingZeroes(int n) {
    
    return n ? n / 5 + trailingZeroes(n / 5) : 0;
    
}