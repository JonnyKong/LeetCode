/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Task{
public:
    TreeNode* add;
    int level;
    Task(TreeNode* add_, int level_) : add(add_), level(level_) {}
};

void traverse(TreeNode* root, vector<vector<int>> & result){
    if(root == NULL) return;
    queue<Task> tasks; tasks.push(Task(root, 0));
    while(!tasks.empty()){
        Task temp = tasks.front(); tasks.pop();
        //if(result.size() <= temp.level) 
        result.resize(temp.level + 1);
        result[temp.level].push_back(temp.add -> val);
        if(temp.add -> left) tasks.push(Task(temp.add -> left, temp.level + 1));
        if(temp.add -> right) tasks.push(Task(temp.add -> right, temp.level + 1));
    }
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result);
        return result;
    }
};