/**
 * Greedy O(n). However, tricky to implement.
 * 
 * I first came up with O(n^2) greedy solution. However, we can use stacks to
 * optimize to O(n).
 * 
 * Several implementation issues:
 * 1) Make sure to get rid of leading 0s
 * 2) Make sure to use all k. For example "12345" the stack will not do any
 *      pop operation. Have to manually pop.
 * 3) If result is "", make sure to return 0.
 */

class Solution {
public:

    string removeKdigits(string num, int k) {

        string result = "";
        for(int i = 0; i < num.length(); ++i) {
            while(!result.empty() && num[i] < result.back() && k > 0) {
                result.pop_back();
                --k;
            }
            result.push_back(num[i]);
        }
        
        /* Make sure to use up k */
        while(k--)
            result.pop_back();

        /* Trim leading 0s */
        int s = 0;
        while(s < result.length() - 1 && result[s] == '0')
            ++s;
        result.erase(0, s);

        return result.empty() ? "0" : result;
    }

};