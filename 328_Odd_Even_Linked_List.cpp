//
//  328. Odd Even Linked List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* Solution::oddEvenList(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;

  ListNode *p = head, *q = head->next, *add = head->next;

  while (p->next && q->next) {
    p->next = q->next;

    p = p->next;

    q->next = p->next;

    q = q->next;
  }

  p->next = add;

  return head;
}