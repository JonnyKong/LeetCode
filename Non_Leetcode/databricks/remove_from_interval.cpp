// https://www.1point3acres.com/bbs/thread-1072913-1-1.html

#include <vector>

using namespace std;

vector<vector<int>> removeFromInterval(const vector<vector<int>> &intervals,
                                       int idx) {
  vector<vector<int>> ret;

  int intervalIdx = 0;
  int cumRange = 0;

  // Move intervalIdx to the last range that will be preserved
  while (intervalIdx < intervals.size()) {
    int curIntervalRange =
        intervals[intervalIdx][1] - intervals[intervalIdx][0] + 1;
    if (cumRange + curIntervalRange >= idx) {
      break;
    } else {
      cumRange += curIntervalRange;
      intervalIdx++;
    }
  }
  for (int i = 0; i < intervalIdx; i++) {
    ret.push_back(intervals[i]);
  }
  if (intervalIdx == intervals.size()) {
    return ret;
  }

  // Process the interval to be split in half
  if (idx > cumRange) {
    // Copy first half
    ret.push_back({intervals[intervalIdx][0],
                   intervals[intervalIdx][0] + idx - cumRange - 1});
  }
  if (idx < cumRange + intervals[intervalIdx][1] - intervals[intervalIdx][0]) {
    // Copy second half
    ret.push_back({intervals[intervalIdx][0] + idx - cumRange + 1,
                   intervals[intervalIdx][1]});
  }

  // Process the remaining intervals
  intervalIdx++;
  while (intervalIdx < intervals.size()) {
    ret.push_back(intervals[intervalIdx]);
    intervalIdx++;
  }

  return ret;
}

int main() {
  vector<vector<int>> intervals = {{4, 7}, {10, 11}, {13, 15}};
  intervals = removeFromInterval(intervals, 2);

  for (auto &interval : intervals) {
    printf("[%d, %d], ", interval[0], interval[1]);
  }
  printf("\n");
}
