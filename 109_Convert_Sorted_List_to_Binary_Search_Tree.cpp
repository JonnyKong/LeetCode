/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    vector<int> list2vec(ListNode *head) {
        vector<int> ret;
        for (ListNode *p = head; p != NULL; p = p->next) {
            ret.push_back(p->val);
        }
        return ret;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        auto vec = list2vec(head);
        return sortedVecToBST(vec, 0, vec.size());
    }

    TreeNode *sortedVecToBST(const vector<int> &vec, int begin, int end)  {
        if (begin == end) {
            return NULL;
        }

        int root_idx = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode();
        root->val = vec[root_idx];
        root->left = sortedVecToBST(vec, begin, root_idx);
        root->right = sortedVecToBST(vec, root_idx + 1, end);
        return root;
    }
};
