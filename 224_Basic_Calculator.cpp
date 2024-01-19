class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        int sign = 1;   // Sign for the integer currently being parsed
        int result = 0; // Current accumulated result at each level

        stack<int> sign_stk = stack<int>();
        stack<int> result_stk = stack<int>();

        int cursor = 0;
        while (cursor < s.length()) {
            if (isDigit(s[cursor])) {
                int i = cursor; 
                while (i + 1 < s.length() && isDigit(s[i + 1])) {
                    i++;
                }
                int n = stoi(s.substr(cursor, i - cursor + 1));
                result += sign * n;
                cursor = i;
            } else if (s[cursor] == '+') {
                sign = 1;
            } else if (s[cursor] == '-') {
                sign = -1;
            } else if (s[cursor] == '(') {
                sign_stk.push(sign);
                sign = 1;
                result_stk.push(result);
                result = 0;
            } else if (s[cursor] == ')') {
                result = result_stk.top() + sign_stk.top() * result;
                sign_stk.pop();
                result_stk.pop();
            } else {
                // eat whitespaces
            }
            cursor++;
        }

        return result;
    }
};
