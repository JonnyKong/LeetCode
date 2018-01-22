//
//  61. Rotate List.h
//  Project 1
//
//  Created by Jonny Kong on 2/22/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

ListNode* rotateRight(ListNode* head, int k) {
    
    if(!k) return head;
    if(!head || !head -> next) return head;
    
    int length = 1;
    ListNode* temp = head;
    ListNode* previous = head;
    ListNode* end = head;
    while(end -> next){    //calculate length
        
        ++length;
        end = end -> next;
        
    }
    
    k = k % length;
    
    if(!k) return head;
    
    temp = head;
    
    for(int i = 0; i < length - k - 1; ++i){
        
        previous = previous -> next;
        
    }
    
    temp = previous -> next;
    
    end -> next = head;
    
    previous -> next = NULL;
    
    return temp;
    
}