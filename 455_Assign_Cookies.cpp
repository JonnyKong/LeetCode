/* Greedy solution */

class Solution {
public:

    int findContentChildren(vector<int> & g, vector<int> & s) {
        /* Sort in reverse order */
        sort(g.begin(), g.end(), [](int a, int b) -> bool { return a > b; });
        sort(s.begin(), s.end(), [](int a, int b) -> bool { return a > b; });

        int i = 0, j = 0, result = 0;
        while(j < s.size() && i < g.size()) {           /* No cookies left */
            /* Jump over unsatisfied child */
            while(s[j] < g[i]) {
                if(++i == g.size())     /* No childs left */
                    return result;
            }
            /* Give this cookie to this children */
            ++result; ++i; ++j;
        }
        return result;
    }

};