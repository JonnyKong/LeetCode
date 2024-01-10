class Solution {
public:
    int minAddToMakeValid(string s) {
        int ret = 0;
        int pending = 0;
        
        for (char c : s) {
            if (c == '(') {
                pending++;
            } else if (c == ')') {
                if (pending > 0) {
                    pending--;
                } else {
                    ret++;
                }
            } else {
                // Nothing needed
            }
        }

        return ret + pending;
    }
};

/*
Example 1:
())
add 1x (

)))((( -> need to add 6

cnt=0   // number of open closes pending close
ret=0
Scan through the beginning
If (:
    cnt+=1
If ):
    if cnt > 0:
        cnt-=1
    else:
        ret++   // add an open to match this close
*/
