// https://stackoverflow.com/questions/76142856/finding-a-path-between-two-nodes-in-a-k-th-order-fibonacci-tree

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string search(int order, int rootVal, const int targetVal,
              const vector<int> &degrees) {
  if (rootVal == targetVal) {
    return "";
  } else if (targetVal <= rootVal + degrees[order - 2]) {
    return "L" + search(order - 2, rootVal + 1, targetVal, degrees);
  } else {
    return "R" + search(order - 1, rootVal + 1 + degrees[order - 2], targetVal,
                        degrees);
  }
}

string solve(int order, int src, int dst) {
  vector<int> degrees(order + 1);
  degrees[0] = 1;
  degrees[1] = 1;
  for (int i = 2; i < order + 1; i++) {
    degrees[i] = degrees[i - 2] + degrees[i - 1] + 1;
  }

  string path1 = search(order, 0, src, degrees);
  std::cout << "path1: " << path1 << std::endl;
  string path2 = search(order, 0, dst, degrees);

  // Move cursor to first place where path 1 and 2 differ
  int cursor = 0;
  while (cursor < min(path1.size(), path2.size()) &&
         path1[cursor] == path2[cursor]) {
    cursor++;
  }

  string ret;
  for (int i = 0; i < path1.size() - cursor; i++) {
    ret += "U";
  }
  ret += path2.substr(cursor, path2.size() - cursor);
  return ret;
}

int main() { cout << solve(5, 5, 7) << endl; }
