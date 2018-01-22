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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        for(ListNode* p = headA; p; p = p -> next) ++len1;
        for(ListNode* p = headB; p; p = p -> next) ++len2;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if(len1 > len2){
            for(int i = 0; i < len1 - len2; ++i) p1 = p1 -> next;
        }
        else{
            for(int i = 0; i < len2 - len1; ++i) p2 = p2 -> next;
        }
        while(p1 != p2){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};