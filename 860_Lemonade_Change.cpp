/**
 * Trivial greedy
 */

class Solution {
public:
    
    bool lemonadeChange(vector<int>& bills) {
        
        int a[3] = {0};     /* No of 20, 10, 5 bills */

        for(int i = 0; i < bills.size(); ++i) {

            if(bills[i] == 20) {
                a[0]++;
                if(a[1] > 0 && a[2] > 0) {
                    a[1]--; a[2]--;
                } else if(a[2] >= 3) {
                    a[2] -= 3;
                } else {
                    return false;
                }
            }

            else if(bills[i] == 10) {
                a[1]++;
                if(a[2] > 0)
                    a[2]--;
                else
                    return false;
            }
                
            else if(bills[i] == 5) {
                a[2]++;
            }

            else
                assert(false);  /* Will never reach here */
        }
        
        return true;
    }

};