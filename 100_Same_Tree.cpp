//
//  100. Same Tree.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q)
    return 1;

  else if (!p)
    return 0;

  else if (!q)
    return 0;

  else if (q->val != p->val)
    return 0;

  else
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}