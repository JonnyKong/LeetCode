class Solution {
public:
    string shortestPalindrome(string s) {
        string strRev = s;
        reverse(strRev.begin(), strRev.end());

        // Use strncmp over string::substr to avoid copying, otherwise TLE
        const char *cstr = s.c_str();
        const char *cstrRev = strRev.c_str();

        int i;
        for (i = s.length(); i > 0; i--) {
            if (strncmp(cstr, cstrRev + s.length() - i, i) == 0) {
                break;
            }
        }

        // i now contains the length of longest parlindrome from the beginning
        return strRev.substr(0, s.length() - i) + s;
    }
};

/*
Brute force: find longest palin from the beginning
aacecaaa

Step 1:
aacecaaa 
^^^^^^^^

Step 2: 
aacecaaa 
^^^^^^^

Step 3:
Step 2: 
aacecaaa 
^^^^^^
*/
