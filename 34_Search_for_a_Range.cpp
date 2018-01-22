class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>::iterator front = nums.begin();

        front = find(nums.begin(), nums.end(), target);
        
        if(front != nums.end()){
            
            int pos1 = distance(nums.begin(), front);
            
            while(*front == target && front != nums.end()) ++front;
            
            return vector<int>{pos1, distance(nums.begin(), front) - 1};
            
        }
        
        return vector<int>{-1, -1};
        
    }
};