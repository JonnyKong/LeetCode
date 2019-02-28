//
//  112. Path Sum.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool hasPathSum(TreeNode* root, int sum) {
  if (!root)
    return 0;
  else if (root->left == NULL && root->right == NULL)
    return sum == root->val;
  else
    return (hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val));
}