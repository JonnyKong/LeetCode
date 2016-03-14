//
//  165. Compare Version Numbers.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

//Very messy, no value for reference. Better rewrite.

int compareVersion(string version1, string version2) {
    
    int i, j;
    
    string temp1 = version1;
    string temp2 = version2;
    if(temp1.find(".") == string::npos && temp2.find(".") == string::npos){
        
        if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
        else if(atoi(temp1.c_str()) == atoi(temp2.c_str())) return 0;
        else return 1;
        
    }
    
    else if(temp1.find(".") == string::npos && temp2.find(".") != string::npos){
        
        if(atoi(temp1.c_str()) > atoi(temp2.c_str())) return 1;
        else if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
        else{
            
            int tempPos = temp2.find(".") + 1;
            temp2 = temp2.substr(tempPos, temp2.length() - tempPos);
            
            if(temp2.find("1") != string::npos || temp2.find("2") != string::npos || temp2.find("3") != string::npos || temp2.find("4") != string::npos || temp2.find("5") != string::npos || temp2.find("6") != string::npos || temp2.find("7") != string::npos || temp2.find("8") != string::npos || temp2.find("9") != string::npos) return -1;
            
            else return 0;
            
        }
        
    }
    
    else if(temp2.find(".") == string::npos && temp1.find(".") != string::npos){
        
        if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
        else if(atoi(temp1.c_str()) > atoi(temp2.c_str())) return 1;
        else{
            
            int tempPos = temp1.find(".") + 1;
            temp1 = temp1.substr(tempPos, temp1.length() - tempPos);
            
            if(temp1.find("1") != string::npos || temp1.find("2") != string::npos || temp1.find("3") != string::npos || temp1.find("4") != string::npos || temp1.find("5") != string::npos || temp1.find("6") != string::npos || temp1.find("7") != string::npos || temp1.find("8") != string::npos || temp1.find("9") != string::npos) return 1;
            
            else return 0;
            
        }
        
    }
    
    
    while(temp1.find(".") != string::npos && temp2.find(".") != string::npos){
        
        int num1 = atoi(temp1.c_str());
        int num2 = atoi(temp2.c_str());
        
        if(num1 < num2) return -1;
        else if(num1 > num2) return 1;
        else{
            
            i = temp1.find(".") + 1;
            j = temp2.find(".") + 1;
            
            temp1 = temp1.substr(i, temp1.length() - i);
            temp2 = temp2.substr(j, temp2.length() - j);
            
        }
        
        if(temp1.find(".") == string::npos && temp2.find(".") != string::npos){
            
            if(atoi(temp1.c_str()) > atoi(temp2.c_str())) return 1;
            else if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
            else{
                
                int tempPos = temp2.find(".") + 1;
                temp2 = temp2.substr(tempPos, temp2.length() - tempPos);
                
                if(temp2.find("1") != string::npos || temp2.find("2") != string::npos || temp2.find("3") != string::npos || temp2.find("4") != string::npos || temp2.find("5") != string::npos || temp2.find("6") != string::npos || temp2.find("7") != string::npos || temp2.find("8") != string::npos || temp2.find("9") != string::npos) return -1;
                
                else return 0;
                
            }
            
        }
        
        else if(temp2.find(".") == string::npos && temp1.find(".") != string::npos){
            
            if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
            else if(atoi(temp1.c_str()) > atoi(temp2.c_str())) return 1;
            else{
                
                int tempPos = temp1.find(".") + 1;
                temp1 = temp1.substr(tempPos, temp1.length() - tempPos);
                
                if(temp1.find("1") != string::npos || temp1.find("2") != string::npos || temp1.find("3") != string::npos || temp1.find("4") != string::npos || temp1.find("5") != string::npos || temp1.find("6") != string::npos || temp1.find("7") != string::npos || temp1.find("8") != string::npos || temp1.find("9") != string::npos) return 1;
                
                else return 0;
                
            }
            
        }
        
        
    }
    
    if(atoi(temp1.c_str()) < atoi(temp2.c_str())) return -1;
    else if(atoi(temp1.c_str()) == atoi(temp2.c_str())) return 0;
    else return 1;
    
}