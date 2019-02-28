//
//  206. Reverse Linked List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* reverseList(ListNode* head) {
  ListNode *p = head, *q = head, *address = head;

  if (!head)
    return NULL;

  else if (head->next == NULL)
    return head;

  q = q->next;

  while (q) {
    address = q->next;

    q->next = p;

    p = q;

    q = address;
  }

  head->next = NULL;

  return p;
}