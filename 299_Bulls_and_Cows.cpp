//
//  299. Bulls and Cows.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

string getHint(string secret, string guess) {
  int bull = 0;
  int cow = 0;

  int length = secret.length();

  char* a = new char[length];
  char* b = new char[length];
  for (int i = 0; i < length; ++i) a[i] = secret[i];
  for (int i = 0; i < length; ++i) b[i] = guess[i];

  for (int i = 0; i < length; ++i)
    if (secret[i] == guess[i]) bull++;

  int* numberSecret = new int[10];
  int* numberGuess = new int[10];
  memset(numberSecret, 0, 10 * sizeof(int));
  memset(numberGuess, 0, 10 * sizeof(int));

  for (int i = 0; i < length; ++i) {
    numberSecret[secret[i] - 48]++;
    numberGuess[guess[i] - 48]++;
  }

  for (int i = 0; i < 10; ++i) {
    cow += min(numberGuess[i], numberSecret[i]);
  }

  cow -= bull;

  string result = "AB";

  char t[10];
  sprintf(t, "%d", cow);
  string temp = t;
  result.insert(1, temp);
  sprintf(t, "%d", bull);
  string temp2 = t;
  result.insert(0, temp2);

  delete[] a;
  delete[] b;
  delete[] numberSecret;
  delete[] numberGuess;

  return result;
}