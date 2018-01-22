class Solution {
private:
    int count = 0;
    int length;
    int* position;
    inline bool conflict(int n){
        for(register int i = 0; i < n; ++i){
            if(position[i] == position[n] || n - i == abs(position[i] - position[n])) return 1;
        }
        return 0;
    }
    inline void dfs(int n){
        if(n == length){
            ++count;
            return;
        }
        position[n] = 0;
        for(register int i = 0; i < length; ++i){
            if(!conflict(n)) dfs(n + 1);
            ++position[n];
        }
    }
public:
    int totalNQueens(int n) {
        length = n;
        position = new int[n];
        dfs(0);
        return count;
    }
};
