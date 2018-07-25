class Solution {

    public ListNode reverseList(ListNode head) {

        /* Sanity check */
        if(head == null || head.next == null)
            return head;

        ListNode p1 = head;
        ListNode p2 = head.next;
        ListNode p3 = head.next.next;
        p1.next = null;

        while(true) {
            p2.next = p1;

            /* Termination */
            if(p3 == null)
                return p2;

            p1 = p2;
            p2 = p3;
            p3 = p3.next;
        }
    }

}