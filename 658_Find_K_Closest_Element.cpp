/**
 * O(logn + k) binary search.
 * 
 * Original solution: Because even if element not exist in array, we still want
 * to find the closest element. Can't use std::find(). Hand-written binary 
 * search.
 * 
 * New solution: Use std::upper_bound. Note that it returns first number greater
 * than x.
 * 
 * Also, we don't have to add result to an array incrementally. We can mark out
 * the boarders, since result will be a continuous subarray of input.
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
//private:
//    int binary_search(const vector<int> &array, int target);
//    int binary_search_helper(const vector<int> &arr,
//            int target, int l_index, int r_index);
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x);
};

/**
 * Binary search. If duplicates exist, return any of them. If the target does not
 * exist, return the closest.
 */
//int Solution::binary_search(const vector<int> &arr, int target) {
//    return binary_search_helper(arr, target, 0, arr.size() - 1);
//}
//
//int Solution::binary_search_helper(const vector<int> &arr,
//        int target, int l_index, int r_index) {
//    if (l_index + 1 == r_index) {
//        if (target - arr[l_index] < arr[r_index] - target)
//            return l_index;
//        else
//            return r_index;
//    }
//
//    int m_index = l_index + (r_index - l_index) / 2;
//    if (arr[m_index] == target)
//        return m_index;
//    else if(arr[m_index] < target)
//        return binary_search_helper(arr, target, m_index, r_index);
//    else
//        return binary_search_helper(arr, target, l_index, m_index);
//}

vector<int> Solution::findClosestElements(vector<int> &arr, int k, int x) {
//    /* Sanity check */
//    if(arr.empty() || k == 0)
//        return vector<int>();
//    else if(k >= arr.size())
//        return arr;
//
//    deque<int> result;
//    int p = binary_search(arr, x);
//    result.push_back(arr[p]);
//    int l = p - 1, r = p + 1;
//
//    /* Sweep with 2 pointers */
//    for(int i = 0; i < k - 1; ++i) {
//        if(l >= 0 && r < arr.size()) {
//            if(x - arr[l] <= arr[r] - x)
//                --l;
//            else
//                ++r;
//        } else if(l >= 0) {
//            --l;
//        } else if(r < arr.size()) {
//            ++r;
//        }
//    }
//
//    return vector<int>(arr.begin() + l + 1, arr.begin() + r);

    /* Find first number greater than or equal to x */
    int index = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    int l = index - 1, r = index;

    while (k--) {
        if (l >= 0 && r < arr.size()) {
            if(arr[l] - x >= x - arr[r])
                --l;
            else
                ++r;
        } else if (l >= 0) {
            --l;
        } else {
            ++r;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + r);
}

int main() {
    vector<int> a = {1};
    vector<int> b = Solution().findClosestElements(a, 1, 1);
    for(int i : b)
        cout << i << " ";
}