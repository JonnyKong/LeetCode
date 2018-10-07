/** 
 * Trivial.
 * 
 * Have some details. Beware of duplications, so use while instead of if.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int> l(houses.size(), INT_MAX);   /* Distance to closest left side heater */
        vector<int> r(houses.size(), INT_MAX);   /* Distance to closest right side heater */

        for (int i = 0, j = -1; i < houses.size(); ++i) {
            while (j + 1 < heaters.size() && houses[i] >= heaters[j + 1])   /* If -> While */
                ++j;
            if (j >= 0)
                l[i] = houses[i] - heaters[j];
        }
        for (int i = houses.size() - 1, j = heaters.size(); i >= 0; --i) {
            while (j - 1 >= 0 && houses[i] <= heaters[j - 1])
                --j;
            if (j < heaters.size())
                r[i] = heaters[j] - houses[i];
        }

        int result = 0;
        for (int i = 0; i < houses.size(); ++i)
            result = max(result, min(r[i], l[i]));

        return result;
    }
};


int main() {
    vector<int> houses = {1,1,1,1,1,1,999,999,999,999,999};
    vector<int> heaters = {499,500,501};
    int r = Solution().findRadius(houses, heaters);
    cout << r << endl;
    return 0;
}