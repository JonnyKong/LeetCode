//
//  111. Minimum Depth of Binary Tree.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int minDepth(TreeNode* root) {
    
    if(!root) return 0;
    else if(root -> left == NULL && root -> right == NULL) return 1;
    else if(root -> left == NULL) return minDepth(root -> right) + 1;
    else if(root -> right == NULL) return minDepth(root -> left) + 1;
    else{
        
        int minLeft = minDepth(root -> left) + 1;
        int minRight = minDepth(root -> right) + 1;
        return minLeft < minRight ? minLeft : minRight;
        
    }
    
}