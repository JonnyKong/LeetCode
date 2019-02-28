//
//  141. Linked List Cycle.h
//
//
//  Created by Jonny Kong on 3/3/16.
//
//

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
  bool hasCycle(ListNode *head) {
    auto temp = head;

    while (temp) {
      if (temp->val == INT_MIN)
        return 1;

      else if (temp->val != INT_MIN)
        temp->val = INT_MIN;

      temp = temp->next;
    }

    return 0;
  }
};