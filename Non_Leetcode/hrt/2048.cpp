#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Game2048 {
private:
    vector<vector<string>> grid;

public:
    Game2048() {
        grid = vector<vector<string>>(4, vector<string>(4, "."));
    }

    vector<string> slideAndMerge(vector<string> line) {
        vector<string> newLine;
        for (auto &val : line) {
            if (val != ".") newLine.push_back(val);
        }

        vector<string> merged;
        int i = 0;
        while (i < newLine.size()) {
            if (i < newLine.size() - 1 && newLine[i] == newLine[i + 1]) {
                merged.push_back(to_string(stoi(newLine[i]) * 2));
                i += 2; // Skip next since it's merged
            } else {
                merged.push_back(newLine[i]);
                i++;
            }
        }

        // Fill the rest with empty spaces
        while (merged.size() < 4) {
            merged.push_back(".");
        }
        return merged;
    }

    void move_towards(char direction) {
        if (direction == 'L') {
            for (int i = 0; i < 4; i++) {
                grid[i] = slideAndMerge(grid[i]);
            }
        } else if (direction == 'R') {
            for (int i = 0; i < 4; i++) {
                reverse(grid[i].begin(), grid[i].end());
                grid[i] = slideAndMerge(grid[i]);
                reverse(grid[i].begin(), grid[i].end());
            }
        } else if (direction == 'U') {
            for (int j = 0; j < 4; j++) {
                vector<string> col;
                for (int i = 0; i < 4; i++) col.push_back(grid[i][j]);
                vector<string> newCol = slideAndMerge(col);
                for (int i = 0; i < 4; i++) grid[i][j] = newCol[i];
            }
        } else if (direction == 'D') {
            for (int j = 0; j < 4; j++) {
                vector<string> col;
                for (int i = 0; i < 4; i++) col.push_back(grid[i][j]);
                reverse(col.begin(), col.end());
                vector<string> newCol = slideAndMerge(col);
                reverse(newCol.begin(), newCol.end());
                for (int i = 0; i < 4; i++) grid[i][j] = newCol[i];
            }
        }
    }

    string insertValue(int x, int y, int value) {
        if (grid[x][y] != ".") {
            return "Error";
        }
        grid[x][y] = to_string(value);
        return "";
    }

    string processMoves(vector<string> moves) {
        for (const auto &move : moves) {
            char direction = move[0];
            int x = move[4] - '0';
            int y = move[2] - '0';
            int value = move[6] - '0';

            move_towards(direction);
            string error = insertValue(x, y, value);
            if (!error.empty()) {
                return "Error";
            }
        }
        return formatBoard();
    }

    string formatBoard() {
        stringstream ss;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                ss << grid[i][j];
                if (j < 3) ss << ",";
            }
            if (i < 3) ss << "\n";
        }
        return ss.str();
    }
};

int main() {
    Game2048 game;
    vector<string> moves = {"U 0 0 2", "U 1 0 2", "L 3 3 4"};
    string output = game.processMoves(moves);
    cout << output << endl;
    return 0;
}
