//
//  7.Reverse Integer.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int reverse(int x) {
    int sign = 1;
    int i=0;
    if(x < 0){
        sign = -1;
        i++;
    }
    else if (!x) return 0;
    char number[20] = {0};
    sprintf(number, "%d", x);
    long result = 0;
    int time = 0;
    while(number[i]){
        result += (number[i++]-48) * pow(10, time++);
    }
    if(result >= 2147483647)
        return 0;
    if(sign == 1)
        return ((int)result);
    else
        return -1*((int)result);
}