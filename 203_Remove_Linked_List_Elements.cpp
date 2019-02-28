//
//  203. Remove Linked List Elements.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

struct ListNode* removeElements(struct ListNode* head, int val) {
  if (!head) return NULL;

  struct ListNode* p = head->next;

  struct ListNode* q = head;

  while (head->val == val) {
    head = head->next;

    if (!head) return NULL;
  }

  while (p) {
    if (p->val == val) {
      p = p->next;

      q->next = p;

    }

    else {
      q = p;

      p = p->next;
    }
  }

  return head;
}