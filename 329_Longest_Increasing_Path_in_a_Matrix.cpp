class Solution {
public:
    vector<vector<int>> visited;
    int m, n;
    int dfs(const vector<vector<int>> & matrix, int cur, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(matrix[i][j] <= cur) return 0;
        if(visited[i][j]) return visited[i][j];
        int a = dfs(matrix, matrix[i][j], i + 1, j);
        int b = dfs(matrix, matrix[i][j], i, j + 1);
        int c = dfs(matrix, matrix[i][j], i - 1, j);
        int d = dfs(matrix, matrix[i][j], i, j - 1);
        visited[i][j] = max(max(a, b), max(c, d)) + 1;
        return visited[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<int>(n));
        int maxLength = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                maxLength = max(maxLength, dfs(matrix, INT_MIN, i, j));
            }
        }
        return maxLength;
    }
};
