/**
 * No idea.
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size());
        for(int i = 0; i < gas.size(); ++i)
            diff[i] = gas[i] - cost[i];
        
        int minBalance = 0x7fffffff;
        int start = -1;
        int total = 0;  /* If total < 0, impossible */
        /* Find the minimum of fuel balance */
        for(int i = 0; i < gas.size(); ++i) {
            total += diff[i];
            if(total < minBalance) {
                minBalance = total;
                start = (i + 1) % gas.size();
            }
        }
        
        return total < 0 ? -1 : start;
    }
};
