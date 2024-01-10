class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> removed(s.length(), false);
        int pendingClose = 0;

        // First pass: remove excessive closes
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                pendingClose++;
            } else if (c == ')') {
                if (pendingClose > 0) {
                    pendingClose--;
                } else {
                    removed[i] = true;
                }
            }
        }

        // Second pass: remove `pendingClose` opens from the end
        for (int i = s.length() - 1; i >= 0 && pendingClose > 0; i--) {
            if (s[i] == '(') {
                removed[i] = true;
                pendingClose--;
            }
        }
        
        string ret;
        for (int i = 0; i < s.length(); i++) {
            if (!removed[i]) {
                ret += s[i];
            }
        }
        return ret;
    }
};

/*
pending = 0 // number of "(" pending close
if (:
    pending++
if ):
    if pending == 0:
        remove current ")"
// at here, pending > 0 here means more open needs removal

Now we need to remove some opens

safe to always remove from beginning? -> no
safe to always remove from end? -> yes. Proof:
    Assuming ( exists at location i and j, where i < j:
    if it is unsafe to remove j, it is also unsafe to remove i
    because in both cases, at some point to the right of j, pendingClose will be negative

Example 1: 
(()))

Example 2:
)()

Example 3:
))((

Example 4:
( ( ( ) ) )  )  (((( ))
1 2 3 2 1 0 -1  0123 21     -> remove the first -1
( ( ( ) ) )  (((( ))
1 2 3 2 1 0  1234 32    -> need to remove 2 opens

*/
