//
//  59. Spiral Matrix II.h
//
//
//  Created by Jonny Kong on 3/3/16.
//
//

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    if (n == 0) {
      vector<vector<int>> a;

      return a;
    }

    vector<vector<int>> result(n, vector<int>(n));
    vector<vector<bool>> occupied(n, vector<bool>(n, 0));
    result[0][0] = 1;
    occupied[0][0] = 1;

    int direction = 0;

    int i = -1, j = 0;

    int count = 1;

    while (count < n * n) {
      if (direction == 0) {
        ++i;

        ++j;

        while (j < n && !occupied[i][j]) {
          result[i][j] = ++count;

          occupied[i][j++] = 1;
        }

      }

      else if (direction == 1) {
        ++i;

        --j;

        while (i < n && !occupied[i][j]) {
          result[i][j] = ++count;

          occupied[i++][j] = 1;
        }

      }

      else if (direction == 2) {
        --i;

        --j;

        while (j >= 0 && !occupied[i][j]) {
          result[i][j] = ++count;

          occupied[i][j--] = 1;
        }

      }

      else if (direction == 3) {
        --i;

        ++j;

        while (i >= 0 && !occupied[i][j]) {
          result[i][j] = ++count;

          occupied[i--][j] = 1;
        }
      }

      ++direction;

      if (direction == 4) direction = 0;
    }

    return result;
  }
};