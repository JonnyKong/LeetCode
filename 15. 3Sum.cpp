class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fast = nums.begin();
        ++slow;
        ++fast;
        int current = nums[0];
        int result = 1;
        
        while(fast != nums.end()){
            
            if(*fast != current){
                
                current = *fast;
                *slow++ = *fast++;
                ++result;
                
            }
            
            else ++fast;
            
        }
        
        return result;
        
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) return vector<vector<int>>{};
        
        sort(nums.begin(), nums.end());
        
        int position = removeDuplicates(nums);
        
        vector<vector<int>> result;
        
        for(int i = 0; i < position - 2;){
            
            for(int j = i + 1; j < position - 1;){
                
                if(find(nums.begin() + j + 1, nums.begin() + position,  -(nums[i] + nums[j])) != nums.begin() + position){
                    
                    result.push_back(vector<int>{nums[i], nums[j], 0 - nums[i] - nums[j]});
                    
                }
                
                while(nums[j + 1] == nums[j]) ++j;
                
                ++j;
                
            }
            
            while(nums[i + 1] == nums[i]) ++i;
            
            ++i;
            
        }
        
        return result;
        
    }
};