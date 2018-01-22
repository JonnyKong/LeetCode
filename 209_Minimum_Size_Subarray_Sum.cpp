class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int left = 0;
        int right = 0;  //included
        int sum = nums[0];
        int minLength = INT_MAX;
        while(sum < s){
            sum += nums[++right];
            if(right == nums.size()) return 0;
        }
        if(sum > s){
            while(sum > s){
                sum -= nums[left++];
            }
            if(sum < s) sum += nums[--left];
        }
        
        minLength = right - left + 1;

        while(right + 1 < nums.size()){
            sum += nums[++right];
            if(sum > s){
                while(sum > s){
                    sum -= nums[left++];
                }
                if(sum < s) sum += nums[--left];
            }
            if(minLength > (right - left + 1)) minLength = (right - left + 1);
        }
        return minLength;
    }
};