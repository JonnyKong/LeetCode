#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class SnapshotSet {
public:
  // For each element, map element to a list of [version, action], where action
  // is either 1 (added) or 0 (removedint)
  unordered_map<int, vector<pair<int, bool>>> m;
  int v;

  SnapshotSet() : v(0) {}

  bool add(int a) {
    m[a].push_back({v, true});
    return true;
  }

  bool remove(int a) {
    if (m.count(a) == 0) {
      return false;
    } else if (m[a].back().second == 0) {
      return false;
    } else {
      m[a].push_back({v, false});
      return true;
    }
  }

  bool contains(int a) {
    if (m.count(a) == 0) {
      return false;
    } else if (m[a].back().second == 0) {
      return false;
    } else {
      return true;
    }
  }
};

class SnapshotIterator {
  int v;
  SnapshotSet &s;
  unordered_map<int, vector<pair<int, bool>>>::iterator it;

public:
  SnapshotIterator(SnapshotSet &s) : v(s.v), s(s), it(s.m.begin()) {
    s.v++;
    moveToNextValid();
  };

  bool hasNext() { return it != s.m.end(); }

  int getNext() {
    assert(hasNext());
    int ret = it->first;
    it = next(it);
    moveToNextValid();
    return ret;
  }

  void moveToNextValid() {
    while (it != s.m.end() && !binSearch(it->second)) {
      it = next(it);
    }
    // if (it != s.m.end()) {
    //   printf("moved to: %d\n", it->first);
    // } else {
    //   printf("moved to: end\n");
    // }
  }

  bool binSearch(const vector<pair<int, bool>> &vec) {
    // Return whether element is in vec at snapshot version v
    // Find the first larger than, then move back by one
    auto p = upper_bound(vec.begin(), vec.end(), std::make_pair(v, true));
    return prev(p)->second;
  }
};

int main() {
  SnapshotSet s;
  s.add(1);
  s.add(2);
  s.remove(1);
  SnapshotIterator it(s);
  s.add(8);

  while (it.hasNext()) {
    int ret = it.getNext();
    std::cout << ret << std::endl;
  }
}
