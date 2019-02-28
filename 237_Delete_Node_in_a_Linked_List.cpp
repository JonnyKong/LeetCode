//
//  237. Delete Node in a Linked List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

void deleteNode(ListNode* node) { memcpy(node, node->next, 16); }