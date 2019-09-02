#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:

    static int largestRectangleArea(vector<int>& heights) {
        stack<int> s_mono_asc;
        int max_size = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (s_mono_asc.size() > 0 && heights[s_mono_asc.top()] > heights[i]) {
                int height = heights[s_mono_asc.top()];
                s_mono_asc.pop();
                int width = i - (s_mono_asc.empty() ? 0 : (s_mono_asc.top() + 1));
                if (max_size < height * width) 
                    max_size = height * width;
            }
            s_mono_asc.push(i);
        }
        while (!s_mono_asc.empty()) {
            int height = heights[s_mono_asc.top()];
            s_mono_asc.pop();
            int width = heights.size() - (s_mono_asc.empty() ? 0 : (s_mono_asc.top() + 1));
            if (max_size < height * width)
                max_size = height * width;
        }
        return max_size;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        vector<vector<int>> matrix_cum(matrix.size(), vector<int>(matrix[0].size()));
        int max_rectangle = 0;

        // Init first row
        for (int j = 0; j < matrix[0].size(); ++j)
            matrix_cum[0][j] = matrix[0][j] == '1' ? 1 : 0;
        max_rectangle = max(max_rectangle, largestRectangleArea(matrix_cum[0]));

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0')
                    matrix_cum[i][j] = 0;
                else
                    matrix_cum[i][j] = matrix_cum[i - 1][j] + 1;
            }
            int max_rectangle_row = largestRectangleArea(matrix_cum[i]);
            max_rectangle = max(max_rectangle, max_rectangle_row);
        }

        return max_rectangle;
    }
};

int main() {
    vector<vector<char>> a = {
        {'0', '1'},
        {'1', '0'}
    };

    int ret = Solution().maximalRectangle(a);
    cout << ret << endl;
}