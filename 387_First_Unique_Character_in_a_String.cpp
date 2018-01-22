class Solution {
public:
    int firstUniqChar(string s) {
        vector<bool> appeared(256);
        vector<bool> repeated(256);
        for(int i = 0; i < s.length(); ++i) {
            if(appeared[s[i]] == 0) appeared[s[i]] = 1;
            else repeated[s[i]] = 1;
        } 
        for(int i = 0; i < s.length(); ++i) {
            if(repeated[s[i]]) s[i] = 0;
        }
        for(int i = 0; i < s.length(); ++i) {
            if(s[i]) return i;
        }
        return -1;
    }
};