#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfsShortestdist(const vector<vector<char>> &grid,
                    vector<vector<bool>> &visited, const int mode, int i,
                    int j) {
  queue<pair<int, int>> q;
  q.push({i, j});

  int dist = 0;
  bool found = false;
  while (!q.empty()) {
    dist++;
    int qsize = q.size();
    for (int k = 0; k < qsize; k++) {
      auto [i, j] = q.front();
      q.pop();
      visited[i][j] = true;
      // printf("mode %c exploring dist %d, %d, %d\n", mode, dist,i ,j);

      for (auto [di, dj] : directions) {
        int i_ = i + di;
        int j_ = j + dj;
        if (i_ >= 0 && i_ < grid.size() && j_ >= 0 && j_ < grid[0].size()) {
          if (grid[i_][j_] == 'D') {
            // printf("reached %d, %d, return ...\n", i_, j_);
            return dist + 1;
          } else if (grid[i_][j_] != mode) {
            continue;
          }
          q.push({i_, j_});
        }
      }
    }
  }
  return INT_MAX;
}

int findFastestRoute(const vector<vector<char>> &grid,
                     const vector<int> &cost_matrix,
                     const vector<int> &time_matrix) {
  vector<vector<bool>> visited(grid.size(),
                               vector<bool>(grid[0].size(), false));

  // Find 'S'
  int i, j;
  bool found = false;
  for (i = 0; i < grid.size(); i++) {
    for (j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 'S') {
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }

  vector<vector<int>> timeCostsModes;
  for (auto [di, dj] : directions) {
    int i_ = i + di;
    int j_ = j + dj;

    if (i_ >= 0 && i_ < grid.size() && j_ >= 0 && j_ < grid[0].size() &&
        !visited[i_][j_]) {
      int mode = grid[i_][j_];
      if (mode == 'X' || mode == 'S') {
        continue;
      }
      int dist = bfsShortestdist(grid, visited, mode, i_, j_);
      int time = time_matrix[mode - '1'] * dist;
      int cost = cost_matrix[mode - '1'] * dist;
      timeCostsModes.push_back({time, cost, mode - '1'});
      printf("mode %c, dist: %d, time: %d, cost: %d\n", mode , dist, time,
             cost);
    }
  }
  return (*std::min_element(timeCostsModes.begin(), timeCostsModes.end()))[2];
}

int main() {
  vector<vector<char>> grid = {
      {'3', '3', 'S', '2', 'X', 'X'}, {'3', '1', '1', '2', 'X', '2'},
      {'3', '1', '1', '2', '2', '2'}, {'3', '1', '1', '1', 'D', '3'},
      {'3', '3', '3', '3', '3', '4'}, {'4', '4', '4', '4', '4', '4'}};
  vector<int> cost_matrix = {0, 1, 3, 2};
  vector<int> time_matrix = {3, 2, 1, 1};

  cout << (char)(findFastestRoute(grid, cost_matrix, time_matrix) + '1')
       << endl;
  return 0;
}
