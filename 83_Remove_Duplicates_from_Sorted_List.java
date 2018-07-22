class Solution {

    public ListNode deleteDuplicates(ListNode head) {
        /* Sanity check */
        if(head == null)
            return head;

        ListNode p = head;
        ListNode q = head;

        while(p != null) {
            /* Move q to the last duplicate */
            while (q.next != null && q.val == q.next.val)
                q = q.next;

            p.next = q.next;
            p = p.next;
            q = q.next;
        }

        return head;
    }

}