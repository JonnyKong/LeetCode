class Solution {
public:
    static void swap(vector<int> & nums, int m, int n){
        int temp = nums[m];
        nums[m] = nums[n];
        nums[n] = temp;
    }
    
    static void dfs(vector<int> & nums, vector<vector<int>> & result, int m){  //m to be searched
        if(m == nums.size() - 1){
            result.push_back(nums);
            return;
        }
        for(int i = m; i < nums.size(); ++i){
            swap(nums, m, i);
            dfs(nums, result, m + 1);
            swap(nums, m, i);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, result, 0);
        return result;
    }
};