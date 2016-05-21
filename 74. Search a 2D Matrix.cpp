//
//  74. Search a 2D Matrix.h
//  Project 1
//
//  Created by Jonny Kong on 2/28/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return 0;
        
        int i;
        
        if(matrix.size() == 1) i = 0;
        
        else{
            
            for(i = 0; i < m - 1; ++i){
                
                if(matrix[i][0] <= target && matrix[i + 1][0] >= target) break;
                
            }
            
            if(i != m - 1)
                
                if(matrix[i + 1][0] == target) return 1;
            
        }
        
        vector<int>::iterator a;
        a = find(matrix[i].begin(), matrix[i].end(), target);
        return (a != matrix[i].end());
        
    }
};