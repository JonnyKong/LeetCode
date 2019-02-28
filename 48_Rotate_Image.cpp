//
//  48. Rotate Image.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void turn(int& a, int& b, int& c, int& d) {
  int temp = a;
  a = d;
  d = c;
  c = b;
  b = temp;
}

void rotate(vector<vector<int>>& matrix) {
  int a, b, c, d, e, f, g, h;
  int dimension = matrix.size();

  a = 0;
  b = 0;
  c = 0;
  d = dimension - 1;
  e = dimension - 1;
  f = dimension - 1;
  g = dimension - 1;
  h = 0;

  for (; a < dimension / 2; ++a, --d, --e, ++h) {
    for (b = 0, c = 0, f = dimension - 1, g = dimension - 1; b < dimension / 2;
         ++b, ++c, --f, --g) {
      // b c f g are declared outside
      // traversing the matrix requires to RESET value of b, c, f, g

      turn(matrix[a][b], matrix[c][d], matrix[e][f], matrix[g][h]);
    }
  }

  if (dimension % 2) {
    for (int i = 0; i < dimension / 2; ++i) {
      turn(matrix[i][dimension / 2], matrix[dimension / 2][dimension - 1 - i],
           matrix[dimension - 1 - i][dimension / 2], matrix[dimension / 2][i]);
    }
  }