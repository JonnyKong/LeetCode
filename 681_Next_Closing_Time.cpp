/**
 * Keep carry bit. Very delicate.
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  /* Get next element of input smaller than limit. Can wrap around */
  int getNext(const vector<int> &v, int input, int limit) {
    int p = (find(v.begin(), v.end(), input) - v.begin() + 1) % v.size();
    while (v[p] >= limit) p = (p + 1) % v.size();
    return v[p];
  }

 public:
  string nextClosestTime(string time) {
    set<int> s;
    vector<int> v;
    s.insert(time[0] - '0');
    s.insert(time[1] - '0');
    s.insert(time[3] - '0');
    s.insert(time[4] - '0');
    v.assign(s.begin(), s.end());

    bool carry = 1;
    for (int i = 4; i >= 0 && carry; --i) {
      if (i == 2) continue;
      int cur = time[i] - '0', limit, next;
      if (i == 4)
        limit = 10;
      else if (i == 3)
        limit = 6;
      else if (i == 1 && time[0] == '2')
        limit = 4;
      else if (i == 1)
        limit = 10;
      else
        limit = 3;

      next = getNext(v, cur, limit);
      if (next <= cur)
        carry = 1;
      else
        carry = 0;

      time[i] = next + '0';
    }
    return time;
  }
};

int main() {
  string time = "23:59";
  string time_new = Solution().nextClosestTime(time);
  cout << time_new << endl;
}