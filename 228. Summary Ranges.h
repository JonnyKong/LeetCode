//
//  228. Summary Ranges.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

vector<string> summaryRanges(vector<int>& nums) {
    
    vector<string> result;
    
    string temp;
    char tempStr[20] = "000000";
    
    if(nums.empty()) return result;
    
    else if(nums.size() == 1){
        
        sprintf(tempStr, "%d", nums[0]);
        temp = tempStr;
        result.push_back(temp);
        return result;
        
    }
    
    int low = nums[0], high;
    
    for(int i = 0; i < nums.size() - 1; ++i){
        
        if(nums[i] != nums[i + 1] - 1){ // a gap
            
            high = nums[i];
            
            if(low == high){    //single number
                
                sprintf(tempStr, "%d", low);
                temp = tempStr;
                result.push_back(temp);
                
            }
            
            else{   //more than one number
                
                sprintf(tempStr, "%d", low);
                temp = tempStr;
                temp += "->";
                sprintf(tempStr, "%d", high);
                temp += tempStr;
                result.push_back(temp);
                
            }
            
            low = nums[i + 1];
            
        }
        
    }
    
    if(nums[nums.size() - 2] + 1 != nums[nums.size() - 1]){ //last two are not consecutive
        
        sprintf(tempStr, "%d", nums[nums.size() - 1]);
        temp = tempStr;
        result.push_back(temp);
        
    }
    
    else{
        
        sprintf(tempStr, "%d", low);
        temp = tempStr;
        temp += "->";
        sprintf(tempStr, "%d", nums[nums.size() - 1]);
        temp += tempStr;
        result.push_back(temp);
        
    }
    
    return result;
    
}