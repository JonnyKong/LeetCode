//
//  104. Maximum Depth of Binary Tree.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int maxDepth(TreeNode* root) {
  if (!root) return 0;
  int depthLeft = maxDepth(root->left) + 1;
  int depthRight = maxDepth(root->right) + 1;
  return depthLeft > depthRight ? depthLeft : depthRight;
}