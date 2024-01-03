class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (stack.size() == 0 || s[i] != stack[stack.size() - 1]) {
                stack.push_back(s[i]);
            } else {
                stack.pop_back();
            }
        }
        return string(stack.begin(), stack.end());
    }
};

/**

abbaca
 - stack:
 a: a
 b: ab
 b: a (removed b from top)
 a: (empty) (removed a from top)
 c: c
 a: ca

azxxzy:
- stack:
 a: a
 z: az
 x: azx
 x: az (x removed from head)
 z: a (z removed)
 y: ay
*/
