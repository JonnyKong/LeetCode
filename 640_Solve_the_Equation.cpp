class Solution {
public:
    string parseNextToken(string s, int startLoc) {
        /*
        Token :=
            [<sign>] <digits> [x] |
            <=>
        */
        if (s[startLoc] == '=') {
            return "=";
        } else {
            int i = startLoc;
            // Eat prepending + or -
            if (s[i] == '-' or s[i] == '+') {
                i++;
            }
            while (i < s.length() && s[i] != '+' && s[i] != '-' && s[i] != '=') {
                i++;
            }
            return s.substr(startLoc, i - startLoc);
        }
    }

    string solveEquation(string equation) {
        int cursor = 0;
        bool seenEqual = false;
        int numX = 0;       // Sum of X's coefficients when all terms are moved to the LHS
        int numInt = 0;     // Sum of all integers when all terms are moved to the LHS
        
        while (cursor < equation.length()) {
            string token = parseNextToken(equation, cursor);
            cursor += token.length();

            if (token == "=") {
                // Flip sign once pass equal sign, effectively moving RHS terms to LHS
                seenEqual = true;

            } else if (token[token.length() - 1] == 'x') {
                // x
                int isNegative = token[0] == '-';
                if (seenEqual) {
                    isNegative = !isNegative;
                }

                string coefStr = (token[0] == '-' || token[0] == '+') ?
                    token.substr(1, token.length() - 2) :
                    token.substr(0, token.length() - 1);
                int coef = coefStr.length() == 0 ? 1 : stoi(coefStr);
                numX += (isNegative ? -1 : 1) * coef;

            } else {
                // Int
                int isNegative = token[0] == '-';
                if (seenEqual) {
                    isNegative = !isNegative;
                }

                string coefStr = (token[0] == '-' || token[0] == '+') ?
                    token.substr(1, token.length() - 1) :
                    token.substr(0, token.length());
                int coef = stoi(coefStr);
                numInt += (isNegative ? -1 : 1) * coef;
            }
        }   

        if (numX == 0) {
            if (numInt == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        } else {
            return "x=" + to_string(-1 * numInt / numX);
        }
    }
};
