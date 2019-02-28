class Solution {
  int pos;
  int level;
  int length;
  bool type;  // 0 dir, 1 file
  bool hasFile;
  void getNext(const string& s) {
    type = 0;
    level = 0;
    length = 0;
    while (pos < s.length() && s[pos] == '\t') {
      ++pos;
      ++level;
    }
    while (pos < s.length() && s[pos] != '\n') {
      if (s[pos++] == '.') type = 1;
      ++length;
    }
    ++pos;
  }

 public:
  int lengthLongestPath(string input) {
    int total = -1;
    int max = -1;
    hasFile = 0;
    pos = 0;
    stack<int> s;
    while (pos < input.length()) {
      getNext(input);
      if (type) hasFile = 1;
      while (level < s.size()) {
        --total;
        total -= s.top();
        s.pop();
      }
      s.push(length);
      total += length;
      total++;
      if (max < total && type) {
        max = total;
      }
    }
    if (!hasFile) return 0;
    return max;
  }
};