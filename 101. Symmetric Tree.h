//
//  101. Symmetric Tree.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

#ifndef _01__Symmetric_Tree_h
#define _01__Symmetric_Tree_h


#endif /* _01__Symmetric_Tree_h */

bool isSymmetric(TreeNode* root) {
    
    if(!root || !root -> left && !root -> right) return 1;
    
    else if(!root -> left || !root -> right) return 0;
    
    return isSameTree(root -> left, invertTree(root -> right));
    
}

TreeNode* invertTree(TreeNode* root) {
    
    if(!root) return NULL;
    else if(!root -> left && !root->right) return root;
    else{
        
        TreeNode* temp = root -> left;
        root -> left = invertTree(root -> right);
        root -> right = invertTree(temp);
        return root;
        
    }
    
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    
    if(!p && !q) return 1;
    
    else if(!p) return 0;
    
    else if(!q) return 0;
    
    else if(q -> val != p -> val) return 0;
    
    else return( isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right) );
    
}