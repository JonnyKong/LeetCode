/**
 * Question: An Array of integers is given, both +ve and -ve. You need to find 
 *  the two elements such that their sum is closest to zero.
 * 
 * Sorting + 2 pointers. O(NlogN).
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

pair<int, int> minAbsSumPair(vector<int> &nums) {
    /* Sanity check */
    if (nums.size() < 2) {
        cerr << "Invalid input" << endl;
        return make_pair(-1, -1);
    }

    /* Variables to keep track of current sum and minimum sum */
    int sum, min_sum = INT_MAX;
    /* Left and right index variables */
    int l = 0, r = nums.size() - 1;

    pair<int, int> result;
    sort(nums.begin(), nums.end());

    while (l < r) {
        sum = nums[l] + nums[r];
        if (abs(sum) < min_sum) {
            min_sum = abs(sum);
            result = make_pair(l, r);
        }
        if (sum < 0)
            ++l;
        else
            --r;
    }
    return result;
}

int main() {
    vector<int> a = {1, 60, -10, 70, -80, 85};
    pair<int, int> result = minAbsSumPair(a);
    cout << a[result.first] << ", " << a[result.second] << endl;
    return 0;
}