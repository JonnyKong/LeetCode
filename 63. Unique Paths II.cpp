class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n));
        bool avail = 1;
        for(int i = n - 1; i >= 0; --i){
            if(obstacleGrid[m - 1][i]) avail = 0;
            if(avail) path[m - 1][i] = 1;
        }
        avail = 1;
        for(int i = m - 1; i >= 0; --i){
            if(obstacleGrid[i][n - 1]) avail = 0;
            if(avail) path[i][n - 1] = 1;
        }
        for(int i = m - 2; i >= 0; --i){
            for(int j = n - 2; j >= 0; --j){
                path[i][j] = obstacleGrid[i][j] ? 0 : path[i + 1][j] + path[i][j + 1];
            }
        }
        return path[0][0];
    }
};