class Solution {
public:
    
    void dfs(vector<int> & result, int current, int limit) {
        if(current <= limit) result.push_back(current);
        for(int i = 0; i < 10; ++i) {
            if(current * 10 + i <= limit) dfs(result, current * 10 + i, limit);
            else break;
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        if(n < 1) return vector<int>();
        else if(n < 2) return vector<int>{1};
        else{
            for(int i = 1; i < 10; ++i) dfs(result, i, n);
        }
        return result;
    }
};