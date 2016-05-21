class Solution {
public:
    const int alive = 0xf000000;
    const int die =   0x0f00000;
    int sizeA;
    int sizeB;
    void update(vector<vector<int>> & board, int m, int n){
        int count = 0;
        if(m - 1 >= 0){ //up
            if(board[m - 1][n] & 1) ++count;
            if(n - 1 >= 0){ //upleft
                if(board[m - 1][n - 1] & 1) ++count;
            }
            if(n + 1 < sizeB){  //upright
                if(board[m - 1][n + 1] & 1) ++count;
            }
        }
        if(m + 1 < sizeA){  //down
            if(board[m + 1][n] & 1) ++count;
            if(n - 1 >= 0){
                if(board[m + 1][n - 1] & 1) ++count;
            }
            if(n + 1 < sizeB){
                if(board[m + 1][n + 1] & 1) ++count;
            }
        }
        if(n - 1 >= 0){
            if(board[m][n - 1] & 1) ++count;
        }
        if(n + 1 < sizeB){
            if(board[m][n + 1] & 1) ++count;
        }
        if((board[m][n] & 1) && count == 2 || count == 3){
            board[m][n] |= alive;
        }
        else board[m][n] |= die;
    }
    void nextState(vector<vector<int>> & board, int m, int n){
        if(board[m][n] & alive) board[m][n] = 1;
        else board[m][n] = 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        sizeA = board.size();
        sizeB = board[0].size();
        if(sizeA == 0 || sizeB == 0) return;
        if(sizeA == 1 && sizeB == 1){
            board[0][0] = 0;
            return;
        }
        for(int i = 0; i < sizeA; ++i){
            for(int j = 0; j < sizeB; ++j){
                update(board, i, j);
            }
        }
        for(int i = 0; i < sizeA; ++i){
            for(int j = 0; j < sizeB; ++j){
                nextState(board, i, j);
            }
        }
    }
};