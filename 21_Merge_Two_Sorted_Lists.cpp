//
//  21. Merge Two Sorted Lists.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (!l1 && !l2)
    return NULL;
  else if (!l1 || !l2)
    return l1 ? l1 : l2;

  bool condition = 0;  // l1 smaller than l2
  if (l2->val < l1->val) condition = 1;

  ListNode* p = l1;
  ListNode* q = l2;

  if (!condition) {
    p = l1;
    q = l2;

  }

  else {
    p = l2;
    q = l1;
  }

  ListNode *temp1, *temp2;

  while (p->next && q) {
    if ((q->val) < (p->next->val)) {
      temp1 = p->next;
      temp2 = q->next;
      p->next = q;
      q->next = temp1;
      p = p->next;
      q = temp2;

    }

    else
      p = p->next;
  }

  if (p->next == NULL) {
    p->next = q;
  }

  if (!condition)
    return l1;

  else
    return l2;
}