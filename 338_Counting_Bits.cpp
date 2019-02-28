class Solution {
 public:
  vector<int> countBits(int num) {
    if (num == 0) {
      return vector<int>(1, 0);
    } else if (num == 1) {
      return vector<int>{0, 1};
    }
    vector<int> result(num + 1);
    result[0] = 0;
    result[1] = 1;
    int size = 1;
    int count = 2;
    int current = 2;
    while (1) {
      current = count;
      for (int i = 0; i < size; ++i) {
        if (count == num + 1) {
          return result;
        }
        result[current + i] = result[current + i - size];
        ++count;
      }
      for (int i = 0; i < size; ++i) {
        if (count == num + 1) {
          return result;
        }
        result[current + i + size] = result[current + i - size] + 1;
        ++count;
      }
      size <<= 1;
    }
  }
};