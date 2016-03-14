//
//  19. Remove Nth Node From End of List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    int i = 0;
    
    ListNode* p = head;
    
    while(p -> next){
        
        p = p -> next;
        
        ++i;
        
    }
    
    if(i == 0) return NULL; //only one node
    
    else if(i == 1){
        
        if(n == 1){
            
            head -> next = NULL;
            
            return head;
            
        }
        
        else return head -> next;
        
    }
    
    if(i == n - 1) return head -> next;
    
    p = head;
    
    for(int j=0; j < i - n; ++j){
        
        p = p -> next;
        
    }
    
    p -> next = p -> next -> next;
    
    return head;
    
}