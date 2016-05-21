//
//  2. Add Two Numbers.h
//  
//
//  Created by Jonny Kong on 3/4/16.
//
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* preP;
        ListNode* preQ;
        bool next = 0;
        
        while(p && q){
            
            p -> val += q -> val;
            
            if(next){
                
                p -> val += 1;
                
                next = 0;
                
            }
            
            if(p -> val > 9){
                
                p -> val -= 10;
                
                next = 1;
                
            }
            
            q -> val = p -> val;
            
            preP = p;
            
            preQ = q;
            
            p = p -> next;
            
            q = q -> next;
            
        }
        
        if(p && !q){
            
            if(!next) return l1;
            
            while(p){
                
                p -> val += 1;
                
                next = 0;
                
                if(p -> val > 9){
                    
                    p -> val -= 10;
                    
                    next = 1;
                    
                }
                
                preP = p;
                
                p = p -> next;
                
                if(!next) return l1;
                
                if(!p) break;
                
            }
            
            preP -> next = new ListNode(1);
            
            return l1;
            
        }
        
        else if(!p && q){
            
            if(!next) return l2;
            
            while(q){
                
                q -> val += 1;
                
                next = 0;
                
                if(q -> val > 9){
                    
                    q -> val -= 10;
                    
                    next = 1;
                    
                }
                
                preQ = q;
                
                q = q -> next;
                
                if(!next) return l2;
                
                if(!q) break;
                
            }
            
            preQ -> next = new ListNode(1);
            
            return l2;
            
        }
        
        else if(!p && !q){
            
            if(next){
                
                preP -> next = new ListNode(1);
                
                return l1;
                
            }
            
            else return l1;
            
        }
        
    }
};