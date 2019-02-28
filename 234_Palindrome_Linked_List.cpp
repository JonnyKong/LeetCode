//
//  234. Palindrome Linked List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isPalindrome(ListNode* head) {
  int length = 0;
  ListNode* temp = head;
  ListNode* temp1;

  while (temp != NULL) {
    ++length;
    temp = temp->next;
  }

  temp1 = head;
  for (int i = 0; i < (length - 1) / 2; ++i)
    temp1 = temp1->next;  // Move temp to middle
  // length is odd: center of the list;
  // length is even: last of the first half

  for (int i = 0; i < (length / 2); ++i) {  // first move, then examine

    temp1 = temp1->next;

    // moving temp from the start every time
    temp = head;
    for (int j = 0; j < (length / 2 - 1 - i); ++j) temp = temp->next;

    if (temp->val != temp1->val) return 0;
  }

  return 1;
}