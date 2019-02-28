/**
 * Greedy O(n)
 *
 * Algorithm:
 * 1) Sort the ballons using right bound
 * 2) Shoot an arrow at this right bound (greedy step)
 * 3) Move to next one
 *
 * *** IMPORTANT:
 * Because we do not care about when a specific ballon burst, we can optimize
 * from O(n^2) to O(n).
 * See commented out section.
 */

class Solution {
 public:
  int findMinArrowShots(vector<pair<int, int>> &points) {
    /* Sanity check */
    if (points.empty()) return 0;

    /* Sort using end point */
    auto com = [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
      return a.second < b.second;
    };
    std::sort(points.begin(), points.end(), com);

    // vector<bool> visited(points.size(), 0);
    int result = 1;
    int arrayPos = points[0].second;
    for (int i = 1; i < points.size(); ++i) {
      // if(visited[i])
      //     continue;
      if (arrayPos < points[i].first) {
        ++result;
        arrayPos = points[i].second;
      }
      // for(int j = i + 1; j < points.size(); ++j) {
      //     if(points[i].second >= points[j].first)
      //         visited[j] = 1;
      // }
      // ++result;
    }

    return result;
  }
};