/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse_helper(ListNode* head, int k) {
        ListNode *cur = head -> next, *old = head, *n;
        for(int i = 1; i < k; ++i) {
            n = cur -> next;
            cur -> next = old;
            old = cur;
            cur = n;
        }
        head -> next = n;
        return old;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Sanity check
        if(k == 1) return head;

        // List length
        int length = 0;
        for(ListNode *p = head; p != NULL; p = p -> next) ++length;
        int times = length / k;
        if(times == 0) return head;
        ListNode *result;

        ListNode *cur = head, *prev;
        for(int i = 0; i < times; ++i) {
            if(i == 0) {
                result = reverse_helper(cur, k);
            }
            else {
                prev -> next = reverse_helper(cur, k);
            }
            prev = cur;
            cur = cur -> next;
        }
        return result;
    }
};
