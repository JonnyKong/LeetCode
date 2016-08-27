struct node {
    int* p;
    int row;
    int col;
    node(int* _p, int _row, int _col) : p(_p), row(_row), col(_col) {}
    bool operator< (const node & other) const { return *p < *(other.p); }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<node> a;
        for(int i = 0; i < matrix.size(); ++i) a.insert(node(&matrix[i][0], i, 0));
        for(int i = 0; i < k - 1; ++i) {
            int currentRow = a.begin() -> row;
            int currentCol = a.begin() -> col;
            a.erase(a.begin());
            if(currentCol + 1 < matrix.size()) {
                a.insert(node(&matrix[currentRow][currentCol + 1], currentRow, currentCol + 1));
            }
        }
        return *(a.begin() -> p);
    }
};
