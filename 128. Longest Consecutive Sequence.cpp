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

    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 1) return 1;
        
        sort(nums.begin(), nums.end());
        
        removeDuplicates(nums);
        
        int count = 1;
        
        int max = 1;
        
        for(int i = 0; i < nums.size(); ++i){
            
            if(nums[i] + 1 == nums[i + 1]) ++count;
            
            else count = 1;
            
            max = max > count ? max : count;
            
        }
        
        return max;

    }
};