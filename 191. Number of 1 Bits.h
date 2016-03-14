//
//  191. Number of 1 Bits.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int hammingWeight(uint32_t n) {
    unsigned int i = 1;
    int result = 0;
    for(int j=0; j<32; j++){
        if(i & n) result++;
        i <<= 1;
    }
    return result;
}