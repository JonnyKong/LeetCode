class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty()) return;
        sum.resize(matrix.size() + 1);
        for_each(sum.begin(), sum.end(), [&matrix](vector<int> & a)->void{ a.resize(matrix[0].size() + 1); });
        for_each(sum[0].begin(), sum[0].end(), [](int & a)->void{ a = 0; });
        for_each(sum.begin(), sum.end(), [](vector<int> & a)->void{ a[0] = 0; });
        for(int i = 1; i < matrix.size() + 1; ++i){
            for(int j = 1; j < matrix[0].size() + 1; ++j){
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sum.empty()) return 0;
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};