/**
 * Trivial DFS.
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;


class Solution {
private:
    bool dfs(vector<vector<char>> &board, const string &word,
            int i, int j, int index) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        else if (board[i][j] & 0x80)
            return false;
        else if (word[index] != board[i][j])
            return false;
        else if (index == word.length() - 1)
            return true;

        board[i][j] |= 0x80;
        if (dfs(board, word, i - 1, j, index + 1) ||
                dfs(board, word, i + 1, j, index + 1) ||
                dfs(board, word, i, j - 1, index + 1) ||
                dfs(board, word, i, j + 1, index + 1))
            return true;
        board[i][j] &= 0x7f;
        return false;
    }
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty())
            return false;
        else {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};


int main() {
    vector<vector<char>> input {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    cout << Solution().exist(input, string("ABCCED")) << endl;
    return 0;
}