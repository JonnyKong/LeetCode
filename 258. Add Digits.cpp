//
//  258. Add Digits.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int addDigits(int num) {
    
    return num - 9 * (int)((num - 1) / 9);
    
}