//
//  202. Happy Number.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int next(int n) {
  int result = 0;
  long time = 10;  // possibility of overflow!!!!!!!!!!!!!!!!!!!!
  int res;

  while (n) {
    res = (n % time) / (time / 10);

    result += pow(res, 2);

    n -= n % time;

    time *= 10;
  }

  return result;
}

bool isHappy(int n) {
  vector<int> record;
  int time = 0;

  while (1) {
    record.push_back(n);

    n = next(n);

    if (n == 1) return 1;

    for (int i = 0; i < time; ++i) {
      if (record[i] == n) return 0;
    }

    ++time;
  }
}