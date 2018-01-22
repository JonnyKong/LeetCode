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

void traverse(TreeNode* root, vector<int> & result){
    if(root == NULL) return;
    queue<Task> tasks; tasks.push(Task(root, 0));
    int level = 0;
    while(!tasks.empty()){
        Task temp = tasks.front(); tasks.pop();
        if(level == temp.level){
            result.push_back(temp.add -> val);
            ++level;
        }
        if(temp.add -> right) tasks.push(Task(temp.add -> right, temp.level + 1));
        if(temp.add -> left) tasks.push(Task(temp.add -> left, temp.level + 1));
    }
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};