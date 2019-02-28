//
//  226. Invert Binary Tree.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

TreeNode* invertTree(TreeNode* root) {
  if (!root)
    return NULL;
  else if (!root->left && !root->right)
    return root;
  else {
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
  }
}