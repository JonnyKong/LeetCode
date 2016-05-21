/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Task;
class Split;
class Add;

class Task{
public:
    TreeNode* address;
    virtual void execute(vector<int> & result, stack<Task*> & tasks) = 0;
    Task(TreeNode* address_) : address(address_) {}
};

class Add : public Task{
public:
    Add(TreeNode* address_) : Task(address_) {}
    void execute(vector<int> & result, stack<Task*> & tasks) override {
        result.push_back(address -> val);
    }
};

class Split : public Task{
public:
    Split(TreeNode* address_) : Task(address_) {}
    void execute(vector<int> & result, stack<Task*> & tasks) override {
        tasks.push(new Add(address));
        if(address -> right) tasks.push(new Split(address -> right));
        if(address -> left) tasks.push(new Split(address -> left));
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<Task*> tasks;
        if(!root) return result;
        tasks.push(new Split(root));
        while(!tasks.empty()){
            Task* pTemp = tasks.top();
            tasks.pop();
            pTemp -> execute(result, tasks);
            delete pTemp;
        }
        return result;
    }
};

