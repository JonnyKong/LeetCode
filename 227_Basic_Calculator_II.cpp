class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    string parseNext(const string &s, int loc) {
        /*
        Token :=
            " " 
            <int>
            <sign>
        */
        if (s[loc] == ' ') {
            return " ";
        } else if (isDigit(s[loc])) {
            int cursor = loc;
            while (cursor < s.length() && isDigit(s[cursor])) {
                cursor++;
            }
            return s.substr(loc, cursor - loc);
        } else {
            // sign
            return s.substr(loc, 1);
        }
    }
    int calculate(string s) {
        int cursor = 0;
        
        deque<long long> si;  // Ints
        deque<char> ss; // Signs

        while (cursor < s.length()) {
            string t = parseNext(s, cursor);
            printf("parsed token %s at pos %d\n", t.c_str(), cursor);
            cursor += t.length();

            if (t == " ") {
                // Eat whitespaces
                continue;
            } else if (isDigit(t[0])) {
                // Int
                si.push_back(stoll(t));

                // Evaluate * and / ASAP
                if (!ss.empty() && (ss.back() == '*' || ss.back() == '/')) {
                    char c = ss.back();
                    ss.pop_back();
                    long long op2 = si.back();
                    si.pop_back();
                    long long op1 = si.back();
                    si.pop_back();
                    if (c == '*') {
                        si.push_back(op1 * op2);
                    } else {
                        si.push_back(op1 / op2);
                    }
                }
            } else {
                // Sign
                assert(t.length() == 1);
                ss.push_back(t[0]);
            }
        }

        // We have evaluated all * and /, only + and - remaining
        // Since it is left-associative, we make a forward pass
        while (!ss.empty()) {
            char c = ss.front();
            ss.pop_front();
            long long op1 = si.front();
            si.pop_front();
            long long op2 = si.front();
            si.pop_front();
            if (c == '+') {
                si.push_front(op1 + op2);
            } else {
                si.push_front(op1 - op2);
            }
        }

        return si.front();
    }
};
