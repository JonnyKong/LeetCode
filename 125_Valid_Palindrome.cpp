class Solution {
public:
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        } else {
            return c;
        }
    }

    bool isAlphanumeric(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }

    bool isPalindrome(string s) {
        if (s.length() <= 1) {
            return true;
        }

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            // Eat whitespaces
            while (i < s.size() && !isAlphanumeric(s[i])) {
                i++;
            }
            while (j >= 0 && !isAlphanumeric(s[j])) {
                j--;
            }
            if (i >= j) {
                return true;
            }

            if (toLower(s[i++]) != toLower(s[j--])) {
                return false;
            }
        }
        return true;
    }
};