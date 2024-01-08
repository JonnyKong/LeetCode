class Solution {
public:
    vector<string> tokenize(string path) {
        vector<string> ret;
        int cursor = 0;

        while (cursor < path.length()) {
            // Skip over first slash
            cursor++;
            int start = cursor;

            while (cursor < path.length() && path[cursor] != '/') {
                cursor++;
            }

            if (cursor > start) {
                ret.push_back(path.substr(start, cursor - start));
            }
        }
        return ret;
    }

    string simplifyPath(string path) {
        auto tokens = tokenize(path);
        vector<string> stack;    
        
        for (auto t : tokens) {
            if (t == ".") {
                continue;
            } else if (t == "..") {
                if (stack.size() > 0) {
                    stack.pop_back();
                } 
            } else {
                stack.push_back(t);
            }
        }

        string ret;
        if (stack.size() > 0) {
            for (auto t : stack) {
                ret += "/";
                ret += t;
            }
        } else {
            ret += "/";
        }
        return ret;
    }
};
