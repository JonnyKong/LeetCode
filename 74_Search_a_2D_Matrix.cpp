#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /* Search along diagonal */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++j;
            else
                --i;
        }
        return false;
    }
};

int main() {
    vector<int> a = {5,7,7,8,8,10};
    vector<int> b = Solution().searchRange(a, 8);
    cout << b[0] << endl << b[1] << endl;
}