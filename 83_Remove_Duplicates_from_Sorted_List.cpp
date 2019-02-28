//
//  83. Remove Duplicates from Sorted List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* deleteDuplicates(ListNode* head) {
  if (!head || head->next == NULL) return head;

  ListNode* p = head;

  while (p->next) {
    if (p->val == p->next->val)
      p->next = p->next->next;

    else
      p = p->next;
  }

  return head;
}