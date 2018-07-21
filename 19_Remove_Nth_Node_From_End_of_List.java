/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = head;
        int listLength = 1;

        /* Get length of list */
        while(p.next != null) {
            p = p.next;
            listLength++;
        }

        /* If the first node is to be removed */
        if(listLength == n)
            return head.next;

        /* Move to the node preceding the one to be removed */
        p = head;
        for(int i = 0; i < listLength - n - 1; ++i)
            p = p.next;

        /* Remove this node */
        p.next = p.next.next;
        return head;
    }
}



