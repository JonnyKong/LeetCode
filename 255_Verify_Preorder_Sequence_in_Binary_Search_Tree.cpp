#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * O(n) solution: based on the property of pre-order traversal.
 * https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/discuss/68185/C%2B%2B-easy-to-understand-solution-with-thought-process-and-detailed-explanation
 */
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> left_tree;
        int min_thresh = INT_MIN;
        for (int a : preorder) {
            if (a < min_thresh)
                return false;
            while (!left_tree.empty() && left_tree.top() < a) {
                min_thresh = left_tree.top();
                left_tree.pop();
            }
            left_tree.push(a);
        }
        return true;
    }
};



/**
 * O(n^2) solution: analyze patterns. ~1000ms.
 */
class Solution2 {
public:
    /**
     * Should be able to divide preorder into two parts: with the first element being the pivot,
     * all elements in the first part are smaller than pivot, and those in the second part are
     * larger.
     */
    bool verifyPreorderHelper(vector<int> &preorder, int lo, int hi) {

        if (hi - lo + 1 <= 2)
            return true;

        int pivot = preorder[lo];
        int sep_index = -1;
        for (int i = lo + 1; i <= hi; ++i) {
            if (sep_index == -1 && preorder[i] < pivot) {    
            }
            else if (sep_index == -1) {
                sep_index = i;
            }
            else if (preorder[i] > pivot) {
            }
            else {
                return false;
            }
        }

        if (sep_index == -1)
            sep_index = hi + 1;
        
        return verifyPreorderHelper(preorder, lo + 1, sep_index - 1) &&
               verifyPreorderHelper(preorder, sep_index, hi);
    }

    bool verifyPreorder(vector<int>& preorder) {
        return verifyPreorderHelper(preorder, 0, preorder.size() - 1);
    }
};