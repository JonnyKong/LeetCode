#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void flip(vector<vector<char>> &board, int x, int y, char color, int n) {
    board[x][y] = color;
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        vector<pair<int, int>> toFlip;
        while (isValid(nx, ny, n) && board[nx][ny] != '.' && board[nx][ny] != color) {
            toFlip.emplace_back(nx, ny);
            nx += dx[d];
            ny += dy[d];
        }
        if (isValid(nx, ny, n) && board[nx][ny] == color) {
            for (auto [fx, fy] : toFlip) {
                board[fx][fy] = color;
            }
        }
    }
}

pair<int, int> playGame(int n, vector<pair<char, pair<int, int>>> moves) {
    vector<vector<char>> board(n, vector<char>(n, '.'));
    for (auto &[color, pos] : moves) {
        flip(board, pos.first, pos.second, color, n);
    }
    
    int black = 0, white = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'B') black++;
            else if (board[i][j] == 'W') white++;
        }
    }
    return {black, white};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<char, pair<int, int>>> moves(m);
    for (int i = 0; i < m; ++i) {
        char color;
        int x, y;
        cin >> color >> x >> y;
        moves[i] = {color, {x - 1, y - 1}};
    }
    
    auto [black, white] = playGame(n, moves);
    cout << black << " " << white << endl;
    return 0;
}
