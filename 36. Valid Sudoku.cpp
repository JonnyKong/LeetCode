//
//  36. Valid Sudoku.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

bool isValidSudoku(vector<vector<char>>& board){
    
    int numbers[9][9] = {0};
    bool occupied[9] = {0};
    
    for(int i = 0; i < 9; ++i){
        
        for(int j = 0; j < 9; ++j){
            
            if(board[i][j] != '.') numbers[i][j] = board[i][j] - 48;
            
            else numbers[i][j] = 0;
            
        }
        
    }
    
    //rows;
    for(int i = 0; i < 9; ++i){
        
        for(int j = 0; j < 9; ++j){ //clear
            
            occupied[j] = 0;
            
        }
        
        for(int j = 0; j < 9; ++j){
            
            if(numbers[i][j]){
                
                if (occupied[numbers[i][j] - 1]) return 0;
                
                else occupied[numbers[i][j] - 1] = 1;
                
            }
            
        }
        
    }
    
    //columns;
    for(int i = 0; i < 9; ++i){
        
        for(int j = 0; j < 9; ++j){ //clear
            
            occupied[j] = 0;
            
        }
        
        for(int j = 0; j < 9; ++j){
            
            if(numbers[j][i]){
                
                if(occupied[numbers[j][i] - 1]) return 0;
                
                else occupied[numbers[j][i] - 1] = 1;
                
            }
            
        }
        
    }
    
    //squares;
    for(int i = 0; i < 9; i += 3){
        
        for(int j = 0; j < 9; j += 3){
            
            for(int j = 0; j < 9; ++j){ //clear
                
                occupied[j] = 0;
                
            }
            
            for(int m = 0; m < 3; ++m){
                
                for(int n = 0; n < 3; ++n){
                    
                    if(numbers[i + m][j + n]){
                        
                        if(occupied[numbers[i + m][j + n] - 1]) return 0;
                        
                        else occupied[numbers[i + m][j + n] - 1] = 1;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return 1;
    
}