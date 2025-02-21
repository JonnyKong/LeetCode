#include <string>
#include <vector>

using namespace std;

class Solution {
    // 0 means not in comment
    // 1 means have parsed a //
    // 2 means have parsed a /*
    
    static size_t findNextCommentStr(const string &s, int start_pos, int state) {
        // Return the starting position of the next relevant comment str
        if (state == 0) {
            // Look for next "//" or "/*"
            auto p1 = s.find("//", start_pos);
            auto p2 = s.find("/*", start_pos);
            if (p1 == string::npos && p2 == string::npos) {
                return s.size();
            } else if (p1 == string::npos || p2 == string::npos) {
                return p1 == string::npos ? p2 : p1;
            } else {
                return min(p1, p2);
            }
        } else if (state == 1) {
            return s.size();
        } else /* if (state == 2) */ {
            // Look for the next "*/"
            auto p = s.find("*/", start_pos);
            return p == string::npos ? s.size() : p;
        }
    }

public:
    vector<string> removeComments(vector<string>& source) {
        int state = 0;
        vector<string> ret;
        string line;
        for (const auto &s : source) {
            string newline;
            size_t cursor = 0;

            while (cursor < s.size()) {
                // Move to next comment
                size_t cursor_new = findNextCommentStr(s, cursor, state);

                // Include chars that are not part of the comment
                if (state == 0) {
                    newline += s.substr(cursor, cursor_new - cursor);
                }

                // Update state
                if (cursor < s.size()) {
                    string op = s.substr(cursor_new, 2);
                    // printf("cursor_new=%d, found op: %s\n", cursor_new, op.c_str());
                    if (op == "//") {
                        assert (state == 0);
                        state = 1;
                    } else if (op == "/*") {
                        assert (state == 0);
                        state = 2;
                    } else if (op == "*/") {
                        assert (state == 2);
                        state = 0;
                    }
                }
                cursor = cursor_new + 2;
            }

            line += newline;
            if (state != 2) {
                if (line != "") {
                    printf("add: %s\n", line.c_str());
                    ret.push_back(line); 
                }
                line = "";
            }
            if (state == 1) {
                // "//" only affects one line
                state = 0;
            }
        }
        return ret;
    }
};
