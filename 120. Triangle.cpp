//
//  120. Triangle.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

int minimumTotal(vector<vector<int>>& triangle) {
    
    int i, j;
    
    if(triangle.size() == 1) return triangle[0][0];
    
    vector<vector<int>> height;
    height.resize(triangle.size());
    for(i = 0; i < triangle.size(); ++i){
        
        height[i].resize(i + 1);
        
    }
    
    height[0][0] = triangle[0][0];
    
    for(i = 1; i < triangle.size(); ++i){
        
        height[i][0] = height[i-1][0] + triangle[i][0];  //height on the slope
        height[i][i] = height[i-1][i-1] + triangle[i][i];
        
        for(j = 1; j < i; ++j){
            
            height[i][j] = min(height[i - 1][j - 1], height[i - 1][j]) + triangle[i][j];
            
        }
        
    }
    
    int minHeight = height[triangle.size() - 1][0];
    
    for(i = 1; i < triangle.size(); ++i){
        
        if(height[triangle.size() - 1][i] < minHeight) minHeight = height[triangle.size() - 1][i];
        
    }
    
    return minHeight;
    
}