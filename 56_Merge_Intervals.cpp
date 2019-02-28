#include <iostream>
#include <vector>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty()) return intervals;

    sort(intervals.begin(), intervals.end(),
         [](const Interval &lhs, const Interval &rhs) -> bool {
           return lhs.start < rhs.start;
         });
    vector<Interval> result;
    int current = 0;
    while (1) {
      int interval_start = intervals[current].start;
      int max_end = intervals[current].end;
      while (current + 1 < intervals.size() &&
             max_end >= intervals[current + 1].start) {
        current++;
        max_end = max(max_end, intervals[current].end);
      }
      result.push_back(Interval(interval_start, max_end));
      cout << "Adding: " << interval_start << ", " << intervals[current].end
           << endl;
      if (current + 1 < intervals.size())
        current++;
      else
        break;
    }
    return result;
  }
};

int main() {
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 4));
  intervals.push_back(Interval(4, 5));
  vector<Interval> result = Solution().merge(intervals);
  return 0;
}